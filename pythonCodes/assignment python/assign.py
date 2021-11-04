import re
file=open('sum.txt')
print("hello")
sum=0

for line in file:
    numbers=re.findall('[0-9]+',line)
    for num in numbers:
        sum=sum+int(num)

print(sum)
