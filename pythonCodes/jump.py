a,n,mj = input().split(" ")
a = int(a)
n= int(n)
mj = int(mj)
arr = input().split(" ")
x = []
for i in range(a):

          x.append(0)
for i in range(int(n)):

          x[int(arr[i])] = 1

d=0
count=0
while d < a:
              if x[d] ==0:
                d = d+1
              if x[d] == 1 and (d+mj)<=a and x[d+int(mj)-1]==0 :
                d=d+mj
                count = count+1
              if x[d] == 1 and (d+mj)<=a and x[d+int(mj)-1]==1:
                d=d-1


if (d == a):
          print(count)
else:
          print("IMPOSSIBLE")
