import sys
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
numTests = int(cont.pop(0)[0])

newCont = []
for i in range(numTests):
    newCont.append(cont[:3])
    cont = cont[3:]
cont = newCont

for case in cont:
    print (case)
    a = case[1]
    b = case[2]
    for i in range(len(a)):
        a[i] = int(a[i])
    if a == sorted(a):
        print ('Yes')
    elif len(set(b)) != 1:
        print ('Yes')
    else:
        print ('No')
