f= open('cowtip.in','r+')
cont = f.readlines()
f.close()
cont = [i.rstrip('\n') for i in cont]
N = int(cont.pop(0))
cont = [list(i) for i in cont]

#do teh algorithm
"""
    first we check the right bottom,
    then we check the adjacent,
    then we keep doing that check,
    and do it recursively
"""

def legal(arr,n):
    for i in range(n):
        for j in range(n):
            if arr[i][j] == '1':
                return False
    return True

def borderlegal(arr,n):
    for i in range(n):
        if arr[n-1][i] or arr[i][n-1] == '1':
            return False
    return True

def checksquare(arr,n,steps = 0):
    #first make sure if the square itself it legal
    if legal(arr,n):
        return steps
    elif borderlegal(arr,n):
        #return new array with the borders but out
        arr.pop()
        for i in range(n-1):
            i.pop()
        return checksquare(arr,n-1)
    else:
        #now if the border isnt legal, do the thing
        for index in range(n):
            if index[n][index]
print checksquare(cont,N)
