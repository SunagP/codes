for t in range(int(input())):
    n=int(input())
    if n==0:
        print(True)
    else:
        for i in range(14):
            if 2**i==n and n>=2**i:
                print(True)
                break
            else:
                print(False)
