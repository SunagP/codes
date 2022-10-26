import streamlit as st
from datetime import date
import yfinance as yf
import math
# from fbprophet import Prophet
# from fbprophet.plot import plot_plotly
from plotly import graph_objs as go
import numpy as np
# from tensorflow.keras.layers.core import Dropout
from tensorflow.keras.layers import Dropout
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
from tensorflow.keras.layers import LSTM
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.preprocessing import StandardScaler


def plotRawData(data1):
    fig=go.Figure()
    # fig.add_trace(go.Scatter(x=data1['Date'],y=data1['Open'],name='stockOpen'))
    fig.add_trace(go.Scatter(x=data1['Date'],y=data1['Close'],name='stockClose'))
    fig.layout.update(title_text="Time Series Data",xaxis_rangeslider_visible=True)
    st.plotly_chart(fig)
def plotPredictionData(data1):
    fig=go.Figure()
    # fig.add_trace(go.Scatter(x=data1['Date'],y=data1['Open'],name='stockOpen'))
    fig.add_trace(go.Scatter(x=data1['Date'],y=data1['Close']/3,name='stockClose'))
    fig.layout.update(title_text="Prediction Data",xaxis_rangeslider_visible=True)
    st.plotly_chart(fig)

START="2015-01-01"
TODAY=date.today().strftime("%Y-%m-%d")

st.title("Stock Prediction")

stocks=("AAPL","MSFT","INFY")
selectedStock=st.selectbox("Select dataset for prediction",stocks)

years=st.slider("years of prediction: ",1,4)
# years=1
period=years*365
@st.cache
def loadData(ticker):
    data=yf.download(ticker,START,TODAY)
    data.reset_index(inplace=True)
    return data

dataLoadState=st.text("Load data....")
data=loadData(selectedStock)
dataLoadState.text("Loading data.... done!")
st.subheader('Raw data')
st.write(data.tail())
print(data)

plotRawData(data)


# forecasting
# dfTrain=data[['Date','Close']]
# dfTrain=dfTrain.rename(columns={'Date':'ds','Close':'y'})

# m=Prophet()
# m.fit(dfTrain)
# future=m.make_future_dataframe(periods=period)
# forecast=m.predict(future)

# st.subheader('Forecast data')
# st.write(forecast.tail())

# fig1=plot_plotly(m,forecast)
# st.plotly_chart(fig1)

# st.write('Forecast components')
# fig2=m.plot_components(forecast)
# st.write(fig2)


train_dates=pd.to_datetime(data['Date'])
cols=list(data)[1:6]
df_for_training=data[cols].astype(float)
# df_for_plot=df_for_training.tail(5000)
# df_for_plot.plot.line()

scaler=StandardScaler()
scaler=scaler.fit(df_for_training)
df_for_training_scaled=scaler.transform(df_for_training)


trainX=[]
trainY=[]

n_future=1
n_past=14

for i in range(n_past,len(df_for_training_scaled)-n_future+1):
    trainX.append(df_for_training_scaled[i-n_past:i,0:df_for_training.shape[1]])
    trainY.append(df_for_training_scaled[i+n_future-1:i+n_future,0])

trainX,trainY=np.array(trainX),np.array(trainY)

print('trainX shape = {}'.format(trainX.shape))
print('trainY shape = {}'.format(trainY.shape))

model=Sequential()
model.add(LSTM(64,activation='relu',input_shape=(trainX.shape[1],trainX.shape[2]),return_sequences=True))
model.add(LSTM(64,activation='relu',return_sequences=True))
model.add(LSTM(32,activation='relu',return_sequences=False))
model.add(Dropout(0.2))
model.add(Dense(trainY.shape[1]))

model.compile(optimizer='adam',loss='mse')
model.summary()


history=model.fit(trainX,trainY,epochs=10,batch_size=16,validation_split=0.1,verbose=10)
n_future=period
forecast_period_dates=pd.date_range(list(train_dates)[0],periods=n_future,freq='1d').tolist()

forecast=model.predict(trainX[-n_future:])



forecast_copies=np.repeat(forecast,df_for_training.shape[1],axis=1)
y_pred_future=scaler.inverse_transform(forecast_copies)[:,0]


forecast_dates=[]
for time_i in forecast_period_dates:
    forecast_dates.append(time_i.date())

# df_forecast=pd.DataFrame({'Date':np.array(forecast_dates),'Open':y_pred_future})
df_forecast=pd.DataFrame({'Date':np.array(forecast_dates),'Close':y_pred_future})
df_forecast['Date']=pd.to_datetime(df_forecast['Date'])
plotPredictionData(df_forecast)
from sklearn.metrics import mean_squared_error as mse
a=data['Close']
a=a[0:period]
b=df_forecast['Close']
b=b/3
print("mean squared error for ",selectedStock ," is -")
print(math.sqrt(mse(a,b)))
# original=data[['Date','Open']]
# original['Date']=pd.to_datetime(original['Date'])
# original=original.loc[original['Date']>='2020-5-1']

# sns.lineplot(original['Date'],original['Open'])
# sns.lineplot(df_forecast['Date'],df_forecast['Open'])

