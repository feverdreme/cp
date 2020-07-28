import sys
from math import floor as fl
from math import ceil as ce
from math import sqrt
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
num = int(cont.pop(0)[0])

for i in cont:
    x,y,z = [int(j) for j in i]

    #first do the NO cases
    #the max has to occur twice
    if len(set([x,y,z])) == 3 or [x,y,z].count(max(x,y,z)) == 1:
        print("NO")
    else:
        maxx = max(x,y,z)
        minn = min(x,y,z)
        print(f"YES\n{maxx} {minn} {minn}")
