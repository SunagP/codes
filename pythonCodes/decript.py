def decryptPassword(x):
    z=0
    s=list(x)
    # Write your code here
    for i in range(len(s)):
        if s[i].isupper() and s[i+1].islower():
            #b=s[i]
            #s[i]=s[i+1]
            #s[i+1]=b
            (s[i],s[i+1])=(s[i+1],s[i])
        elif s[i].isnumeric() and s[i]!='0':
            for j in range(len(s)-1,-1,-1):


                if s[j]=='0':
                    z=j
                    s[z]=s[i]
                    s[i]='*'
                    break


    a=[i for i in s if i!='*']


    return ''.join(a)

print(decryptPassword('43Ah*ck0rr0nk'))
print("hAck3rr4nk")
