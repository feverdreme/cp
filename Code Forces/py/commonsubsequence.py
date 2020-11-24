import sys
from math import floor as fl
from math import ceil as ce
from math import sqrt
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
num = int(cont.pop(0)[0])

for i in range(num):
    arrs = cont[:3]
    cont = cont[3:]
    l1,l2 = [int(j) for j in arrs.pop(0)]
    arrs[0] = [int(j) for j in arrs[0]]
    arrs[1] = [int(j) for j in arrs[1]]
    ret = list(set(arrs[0]) & set(arrs[1]))
    if ret == []:
        print("NO")
    else:
        print(f"YES\n1 {ret[0]}")
