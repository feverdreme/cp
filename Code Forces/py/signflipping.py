import sys
# from math import floor as fl
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
num = int(cont.pop(0)[0])

nc = []
for i in range(num):
    nc.append(cont[:2])
    cont = cont[2:]
cont = nc

for i in cont:
    n = int(i[0][0])
    nums = [int(j) for j in i[1]]
    nums = [abs(j) - (2*abs(j) * (ind%2)) for ind,j in enumerate(nums)]
    print(str(nums)[1:-1].replace(',',''))
