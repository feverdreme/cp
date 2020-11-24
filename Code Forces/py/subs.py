import sys
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
num = int(cont.pop(0)[0])
cont = cont[0]
cont = [int(i) for i in cont]
sc = set(cont)
cont.sort()
cont = cont[::-1]

ans = None
for i in cont:
    if i-1 in sc:
        ans = int(i)
        break

if ans == None:
    print(cont[0])
else:
    
