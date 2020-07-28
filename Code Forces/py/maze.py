import sys
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
numTests = int(cont.pop(0)[0])

cases  = []
for i in range(numTests):
    n = int(cont[0][0])
    cases.append(cont[:n+1])
    cont = cont[n+1:]
