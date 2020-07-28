import sys
from math import floor as fl
cont = sys.stdin.readlines()
cont = [i.strip('\n') for i in cont]
num = int(cont.pop(0)[0])

for i in cont:
    n = int(i)
    if n <= 2:
        print(1)
    elif n == 3:
        print(2)
    else:
        print(int(fl(n/2)))
