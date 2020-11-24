import sys
from math import floor as fl
from math import ceil as ce
from math import sqrt
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
num = int(cont.pop(0)[0])

for i in range(num):
    n,k,z = [int(j) for j in cont.pop(0)]
    arr = [int(j) for j in cont.pop(0)]
    ptr,score = 0,arr[0]
    wasleft = False
    while k:
        if ptr == n-1:
            #then go left
            z -= 1
            ptr -= 1
            score += arr[ptr]
            wasleft = True
        elif ptr == 0:
            #then go right
            ptr += 1
            score += arr[ptr]
            wasleft = False
        else:
            #decide
            if z and arr[ptr-1] > arr[ptr+1] and not wasleft:
                z -= 1
                ptr -= 1
                score += arr[ptr-1]
                wasleft = True
            else:
                ptr += 1
                score += arr[ptr]
                wasleft = False

        k-=1
    print(score,z)
