import sys
from math import floor as fl
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
num = int(cont.pop(0)[0])

nc = []
for i in range(num):
    n = int(cont[0][0])
    # print(cont[i])
    nc.append(cont[:n+1])
    cont = cont[n+1:]
cont = nc

def formatList(lis):
    for i in lis:
        print(str(i)[1:-1].replace(',',''))

for i in cont:
    print(i)
