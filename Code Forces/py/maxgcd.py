import sys
from math import sqrt
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
n = int(cont.pop(0)[0])
cont = [int(i[0]) for i in cont]

# we simply get a dictionary of factors as we traverse
#then we just find find the max with 2 index

for test in cont:
    n = test+1
    divs  = [0] * (n+1)

    for i in range(n):
        j = 1
        while j<=sqrt(i):
            if i % j == 0:
                divs[j] += 1
            if j**2 != i:
                divs[i//j] += 1
            j += 1
    ind = n
    while divs[ind] <= 1:
        if ind == -1:break
        ind -= 1
    print(ind)
