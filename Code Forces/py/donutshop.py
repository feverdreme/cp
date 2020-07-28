import sys
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
numTests = int(cont.pop(0)[0])

from math import ceil as ce

for i in cont:
    a,b,c = i
    a,b,c = int(a),int(b),int(c)
    ret = ''
    if a >= c:
        ret += '-1 '
    else:
        ret += '1 '

    if c / b >= a:
        ret += '-1 '
    else:
        ret += str(c // (a*b) + 10000)
    print(ret)
