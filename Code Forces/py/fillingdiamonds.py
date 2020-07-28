import sys
from math import floor as fl
from math import ceil as ce
from math import sqrt
cont = sys.stdin.readlines()
cont = [i.strip('\n') for i in cont]
num = int(cont.pop(0)[0])

for i in cont:
    n = int(i)
    print(2**(n-1))

print(2**(int(1E9)-1))
