import sys
cont = sys.stdin.readlines()
cont = [i.strip('\n') for i in cont]
numTests = int(cont.pop(0)[0])
cont  =[int(i) for i in cont]

for i in cont:
    if i%4 == 0:
        print('YES')
    else:
        print('NO')
