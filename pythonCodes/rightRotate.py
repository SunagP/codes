def frequency(l):
 dl1=set(l)
 dl=list(dl1)
 newl=[]
 print(dl)
 for i in dl:
  newl.append(l.count(i))
  print(newl)
  mi=min(newl)
  ma=max(newl)
  print(mi)
  print(ma)
  mil=[]
  mal=[]
 for j in range(len(newl)):
  if newl[j]==mi:

   mil.append(dl[j])
  if newl[j]==ma:

   mal.append(dl[j])

 mil.sort()
 mal.sort()
 return(mil,mal)
print(frequency([13,12,11,13,14,13,7,11,13,14,12,14,14]))
