import sys
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
numTests = int(cont.pop(0)[0])

nc = []
for i in range(numTests):
    nc.append(cont[:2])
    cont= cont[2:]
def check(arr,k):
    for i in arr:
        if arr%k !=0:
            return False

    return True

for i in nc:
    n,k = i.pop(0)
    n,k = int(n),int(k)
    i = [int(j) for j in i]

    count = 0

    while not(check(i,k)):
        for ind,j in enumerate(i):
            if (n+j)%k == 0:
                count += 1
                i.pop(ind)
                break
