import sys
from math import floor as fl
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
num = int(cont.pop(0)[0])

nc = []
for i in range(num):
    nc.append(cont[:2])
    cont = cont[2:]
cont = nc

def checkCorrect(n,arr):
    if arr == [i for i in range(1,n+1)]:
        return True
    else:
        return False

for i in cont:
    n = int(i[0][0])
    arr = [int(j) for j in i[1]]

    count = 0

    if checkCorrect(n,arr):
        print(count)
