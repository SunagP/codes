import json
import urllib
x=0
sum=0
url=input("enter url:")
uh=urllib.open(url)
data=uh.read().decode()
info=json.loads(str(data))
for i in info['comments']:
    x=x+1
    sum=sum+i['count']
print('sum=',sum)
