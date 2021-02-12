def checkprime(number):
  fact=1
  for r in range(2,number):
    if number%r==0:
      fact=fact+1
  return(fact<2)
def primepartition(m):
  for i in range(2,m):
    flag=0
    if checkprime(i) and checkprime(m-i)==True:
      flag=1
      break
  return(flag==1)


print(primepartition(185))
