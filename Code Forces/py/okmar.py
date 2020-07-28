import sys
from math import floor as fl
cont = sys.stdin.readlines()
cont = [i.strip('\n') for i in cont]
num = int(cont.pop(0)[0])

for i in cont:
    n = int(i)
    ret = ''

    for j in range(n):
        ret += '1 '
    print(ret)
