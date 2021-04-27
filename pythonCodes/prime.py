import math
def primeCheck(n) :
    # n=5
    flag = False
    if n>1 :
        for i in range(2,int(math.sqrt(n)+1)):
        # for i in range(2,n//2+1):
            if n%i==0:
                flag = True
                break
        if(flag):
            print(n ,"is not prime number")
        else:
            print(n ,"is a prime number")

    else:
        print(n," is neither prime nor composite")


primeCheck(6)
