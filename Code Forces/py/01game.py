import sys
cont = sys.stdin.readlines()
cont = [i.strip('\n') for i in cont]
numTests = int(cont.pop(0)[0])

for i in cont:
    if i.count('10') > 0 or i.count('01') > 0:
        count = 0
        while i.count('10') > 0:
            i = i.replace('10','',1)
            count += 1
        while i.count('01') > 0:
            i = i.replace('01','',1)
            count += 1
        if count%2 == 1:
            #if odd
            print('DA')
        else:
            print('NET')
    else:
        print('NET')
