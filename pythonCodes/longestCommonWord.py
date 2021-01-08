def lcw(u,v):
    for r in range(len(u)+1):
        lcw[r][len(v)+1]=0
    for c in range(len(v)+1):
        lcw[len(u)+1][c]=0
    max=0
    for c in range(len(v)+1,-1,-1):
        for r in range(len(u)+1,-1,-1):
            if u[r]==v[c]:
                lcw[r][c]=1+lcw[r+1][c+1]
            else :
                lcw[r][c]=0
            if lcw[r][c]>max:
                max=lcw[r][c]
    return(max)

#print(x)
