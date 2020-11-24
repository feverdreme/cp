import sys
from re import *
from math import ceil as ce
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
numTests = int(cont.pop(0)[0])

nc = []
for i in range(numTests):
    nc.append(cont[:2])
    cont = cont[2:]

for table in nc:
    n,k = table.pop(0)
    n,k = int(n),int(k)
    table=table[0][0]
    count = 0
    #first find the number of empty spaces
    table = "2" + table + "2"
    ind1 = [ind for ind,i in enumerate(table) if i == '1' or i == '2']
    empty = []
    ind = 0
    for ind in range(len(ind1)):
        if ind == len(ind1) - 1:break
        empty.append(table[ind1[ind]:ind1[ind+1]+1])
    empty = [i for i in empty if i!="11" and i!='12' and i!='21' and i!= "22"]

    for i in empty:
        tlen = len(i)
        if i[0] == '1':
            tlen += -1 - k
        if i[0] == '2':
            tlen -= 1
        if i[-1] == '1':
            tlen += -1-k
        if i[-1] == '2':
            tlen -= 1
        if tlen > 0:
            count += int(ce(tlen / (k+1)))
    print(count)
