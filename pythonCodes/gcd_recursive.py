def gcd(a,b):
    if a<b:
        (a,b)=(b,a)

    while(a%b)!=0:

        dif=a-b

        (a,b)=(max(b,dif),min(b,dif))

    return(b)

print(gcd(32,15))
