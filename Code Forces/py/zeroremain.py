import sys
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
num = int(cont.pop(0)[0])
nc = []
for i in range(num):
    nc.append(cont[:2])
    cont = cont[2:]
cont = nc

for test in cont:
    n,k = [int(i) for i in test[0]]
    test = [int(i)%k for i in test[1]]
    allnums = set(test)
    dictvals = {i:test.count(i) for i in allnums}
    maxn = max(dictvals.values())
    print(test)
