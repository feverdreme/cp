import sys
from math import floor as fl
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
numTests = int(cont.pop(0)[0])

for i in cont:
    x,y,n = [int(j) for j in i]
    n -= y
    n = fl(n/x)
    print(n*x + y)
