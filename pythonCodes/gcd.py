def gcd(a,b):
    fa=[]
    for i in range(1,a+1):
        if a%i==0 :
            fa.append(i)
    fb=[]
    for i in range(1,b+1):
        if b%i==0 :
            fb.append(i)


    fc=[]
    for f in fa:
        if f in fb:
            fc.append(f)

    return(fc[-1])

print(gcd(32,16))
