def primeCheck(n,m) :
    # flag = False
    for i in range(n,m):
        if n>=0 :
            for j in range(2,i):
                if i%j==0:
                    # flag = True
                    # print(n,"is not a prime number")
                    break
            else:
                print(i,end=" ")

        # else:
        #     print(n,"is neither prime nor composite")


primeCheck(2,10)
