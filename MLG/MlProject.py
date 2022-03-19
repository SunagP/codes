import streamlit as st
from datetime import date
import yfinance as yf
import pickle
# from fbprophet import Prophet
# from fbprophet.plot import plot_plotly
from plotly import graph_objs as go


def plotRawData(data1):
    fig=go.Figure()
    fig.add_trace(go.Scatter(x=data1['Date'],y=data1['Open'],name='stockOpen'))
    fig.add_trace(go.Scatter(x=data1['Date'],y=data1['Open'],name='stockClose'))
    fig.layout.update(title_text="Time Series Data",xaxis_rangeslider_visible=True)
    st.plotly_chart(fig)

START="2015-01-01"
TODAY=date.today().strftime("%Y-%m-%d")

st.title("Stock Prediction")

stocks=("AAPL","GOOG","MSFT","GAME")
selectedStock=st.selectbox("Select dataset for prediction",stocks)

years=st.slider("years of prediction: ",1,4)
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

Pkl_Filename = "Model.pkl"

with open(Pkl_Filename, 'rb') as file:
    m = pickle.load(file)

print(m)


# forecasting
dfTrain=data[['Date','Close']]
dfTrain=dfTrain.rename(columns={'Date':'ds','Close':'y'})

# m=Prophet()
# m.fit(dfTrain)
# future=m.make_future_dataframe(periods=period)
forecast=m.predict(dfTrain)

# st.subheader('Forecast data')
# st.write(forecast.tail())

# fig1=plot_plotly(m,forecast)
# st.plotly_chart(fig1)

# st.write('Forecast components')
# fig2=m.plot_components(forecast)
# st.write(fig2)
