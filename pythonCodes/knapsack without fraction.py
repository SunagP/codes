import operator
n= int(input("number of items "))
m=int(input('max capacity '))
profit=[]
w=[]
print("enter profits:")
for i in range(n):
    profit.append(int(input()))

print("enter weights:")
for i in range(n):
    w.append(int(input()))

pw=[]

for i in range(n):
    pw.append([w[i],profit[i]])
pw=sorted(pw,reverse=True,key=operator.itemgetter(1))

max=0
#f=0
for i in range(n):
    if(m>=pw[i][0] and m>0):
        m-=pw[i][0]
        max+=pw[i][1]
    #else:
        ####max+=m*pw[f][1]/(pw[f][0])



print(max)
