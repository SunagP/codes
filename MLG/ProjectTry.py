import yfinance as yf
from datetime import date
import pickle
START="2015-01-01"
TODAY=date.today().strftime("%Y-%m-%d")
data=yf.download('GOOG',START,TODAY)
data.reset_index(inplace=True)
print(data)
dfTrain=data[['Date','Close']]
print(dfTrain)

Pkl_Filename = "Model.pkl"

with open(Pkl_Filename, 'rb') as file:
    Pickled_LR_Model = pickle.load(file)

print(Pickled_LR_Model)
