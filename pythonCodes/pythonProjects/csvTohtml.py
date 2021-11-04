import pandas as pd
print("hi")

data = pd.read_csv(r"C:\Users\Asus\Desktop\Price.csv",index_col = 0)
data.to_html(r"C:\Users\Asus\Desktop\data1.html")
