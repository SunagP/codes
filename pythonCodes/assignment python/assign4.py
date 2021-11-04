# To run this, download the BeautifulSoup zip file
# http://www.py4e.com/code3/bs4.zip
# and unzip it in the same directory as this file

import urllib.request, urllib.parse, urllib.error
from bs4 import BeautifulSoup
import ssl

# Ignore SSL certificate errors
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE
c=0
b=0
url = input('Enter - ')
html = urllib.request.urlopen(url, context=ctx).read()
soup = BeautifulSoup(html, 'html.parser')

# Retrieve all of the anchor tags
tags = soup('a')
for c in range(7):
    b=0
    for tag in tags:
        if b==18:break
        x=tag.get(('href', None)
        b=b+1
    html = urllib.request.urlopen(x, context=ctx).read()
    soup = BeautifulSoup(html, 'html.parser')
    tags=soup('a')
y=x.split('_')
z=y[z].split('.')
print(z[0])
