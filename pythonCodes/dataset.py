import pandas as pd
import os
import shutil
x = pd.read_excel("dataset1.xlsx")
print(x["fname"].head())
y=[]
for i in x["fname"]:
    y.append(str(int(i))+".wav")
#print(y[0])
a = os.getcwd()
os.chdir(a+"\\FSD50K.dev_audio")
path=os.getcwd()
for j in os.listdir(path):
    if j in y:
        shutil.move(j,"C:\\Users\\Asus\\Desktop\\pyhonCodes\\filteredDataSet")
        #print(j)
