import pandas as pd
x = []
df = pd.read_excel(r'C:\Users\Asus\Downloads\Student Database Batch-2023 (Responses).xlsx')
for i in range(len(df)):

    if type(df["Number of active backlogs"][i]) == int:
        pass 
    else:
        x.append(df.index[i])
df1 = df.drop(x)

y = df1["Number of active backlogs"] > 0
usn = list(df1["USN"][y])
#print(usn)
df2 = pd.read_excel(r'C:\Users\Asus\Downloads\Cisco 2023 for coordinators.xlsx')
# print(len(df2))
t = []
new_usn = list(df2["USN"])
for i in usn:
    if i in new_usn:
        t.append(i)
df3 = df2[~df2['USN'].isin(t)]
df3.to_excel(r"C:\Users\Asus\Downloads\output.xlsx")
# for i in usn:
#     if i in df.values :
#         new_usn.append((i))
# print(len(usn))
# print(len(t))
# #print(usn[-5])
# df3 = df2.drop(['1BM19CS033', '1BM19CS037', '1BM20CS401' ,'1BM19CS061' ,'1BM19CS088'])
# print(len(df2))
# print(len(df3))

#print(len(df3))

# rt = []
# for i in range(len(df2)):
#     #print(u)
#     if df['USN'][i] in usn:
#         rt.append(df2.index[i])
# print(rt)
# print(df1["Number of active backlogs"][0])
# print(len(y))
# print(usn)
# print(df.index[2])
# print(len(df))
# print(len(df1))
# print(x)