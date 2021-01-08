def onehop(l):
    new=[]
    l.sort()
    print(l)
    for i in range(len(l)):
         for j in range(len(l)):
            if l[i]!=l[j]:
                if l[i][1]==l[j][0]:
                    q=l[i][0]
                    w=l[j][1]
                    if q!=w:
                        t=[q,w]
                        t=tuple(t)
                        if t not in new:
                            new.append(tuple(t))
    new.sort()
    return (new)


print(onehop([(2,3),(1,2),(3,1),(1,3),(3,2),(2,4),(4,1)]))
