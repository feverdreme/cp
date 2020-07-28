import sys
from itertools import *
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
# numTests = int(cont.pop(0)[0])

cont.pop(0)
for i in cont:
    t = i[0]
    #delete every even
    ret = t[0]
    i = 1
    while i <= len(t):
        ret += t[i]
        i += 2
    print(ret)
