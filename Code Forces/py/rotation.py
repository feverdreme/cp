import sys
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
num = int(cont.pop(0)[0])

a,b = cont[0],cont[1]
a,b = a*2,b*2

maxPairs = 0

a = {ind:i for ind,i in enumerate(a)}
b = {ind:i for ind,i in enumerate(b)}

for nr in range(num):
    count = 0
    for i in range(num):
        if a[i+nr] == b[i]:
            count += 1

    maxPairs = max(maxPairs,count)
    if maxPairs == num:
        break
print (maxPairs)
