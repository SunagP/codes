def primeCheck(n) :
    # flag = False
    if n>1 :
        for i in range(2,n):
            if n%i==0:
                # flag = True
                print(n,"is not a prime number")
                break
        else:
            print(n ,"is  prime number")

    else:
        print(n,"is neither prime nor composite")


primeCheck(0)
