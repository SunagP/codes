import urllib
import json

serviceurl = "http://py4e-data.dr-chuck.net/json?"

while True:

    address = input("Enter location: ")

    if len(address) < 1 : break

    url = serviceurl + urllib.urlencode({'sensor':'false','address':address})

    print('Retrieving',url)

    uh =urllib.urlopen(url)
    data = uh.read()
    print('Retrived',len(data),'characters')

     js = json.loads(str(data))
    #except: js = None
        #print('==== Failure To Retrieve ====')
    #    print(data)
    #    continue

    placeid = js["results"][0]['place_id']
    print("Place id",placeid)
