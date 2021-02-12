def remove(l):
    x = list(set(l))
    #print(x)
    for i in range(len(x)):
        y = l.count(x[i])
        #print(y)
        while(y>1):
            l.remove(x[i])
            y = y-1
    return l


print(remove([1,2,1,3]))


# def Remove(l):
#     l.reverse()
#     y =[]
#     for i in l:
#         if i not in y:
#             y.append(i)
#
#     y.reverse()
#     return y
# print(Remove([1,2,1,3]))
