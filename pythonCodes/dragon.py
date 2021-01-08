R,C,K,D=input().split()
D=int(D)
R=int(R)
K=int(K)
C=int(C)
dP=list()
dist=0
store=dict()
for g in range(D):
        x,y=input().split()
        x=int(x)
        y=int(y)
        dP.append([x,y])

ans=999999
from itertools import combinations
comb = combinations(dP, K)
list_comb=list()
for i in list(comb):
    list_comb.append(sorted(i))

dIP=[0,0]
store=dict()
for row in list_comb:
    for column in range(len(row)):
         if row[:column+1] in store.values():
             spl = row[:column + 1]
             p=spl[len(spl) - 1:len(spl)]

             dist=list(store.keys())[list(store.values()).index(row[:column+1])]
             dIP[0] = p[0][0]
             dIP[1] = p[0][1]

         else:
            r=row[column][0]
            c=row[column][1]
            dist = dist + abs(dIP[0] - r) + abs(dIP[1] - c)
            dIP[0] = r
            dIP[1] = c
            sub_part=[]
            sub_part=row[:column+1]
            store[dist]=sub_part

    if ans>dist:
        ans=dist
    dist=0
    dIP[0] = 0
    dIP[1] = 0
print(ans)
