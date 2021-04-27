def fun(x):
    return lambda a,b:a*b*x

x = fun(2)

y=x(3,4)

print(y)


def filfun(x):
    if x % 2 ==0:
        return True
    else:
        return False

x = filter(filfun,range(10))

print(list(x))#prints all the values that are true


def filfun(x):
    if x % 2 ==0:
        return x*2
    else:
        return x*3

x = map(filfun,range(10))

print(list(x))
