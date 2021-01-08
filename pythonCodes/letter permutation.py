from itertools import permutations

def lexicographical_permutation(str):
    perm = sorted(''.join(chars) for chars in permutations(str))
    arr=[]
    for x in perm:
        arr.append(x)
    for a,b in enumerate(arr):
        if(b=="fjadbihgec"):
            print(arr[a])
            print(arr[a+1])


str ='abcdefghij'
lexicographical_permutation(str)
