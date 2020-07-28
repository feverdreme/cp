import sys
from math import floor as fl
from math import ceil as ce
from math import sqrt
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
num = int(cont.pop(0)[0])

nc = []
for i in range(num):
    nc.append(cont[:2])
    cont = cont[2:]
cont = nc

for i in cont:
    n = i.pop(0)
    i = [int(j) for j in i[0]]

    ret = []
    while len(i) != 0:
        first = i.pop(0)
        ret.append(first)
        i.remove(first)

    retstr = ''
    for j in ret:
        retstr += f"{j} "
    print(retstr)
