def frequency(l):
    x=set(l)
    x=list(x);
    print(x)
    cl = []
    for i in x:
        cl.append(l.count(i))
        print(cl)
        mi = min(cl)
        ma = max(cl)
        print(mi,ma)
        minl = []
        maxl = []
    for j in range(len(cl)):
        if cl[j]==mi:
            minl.append(x[j])
        if cl[j]==ma:
            maxl.append(x[j])
    minl.sort()
    maxl.sort()
    return(minl,maxl)


print(frequency([1,1,2,3,4,1]))
