import sys
from math import floor as fl
from math import ceil as ce
from math import sqrt
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
num = int(cont.pop(0)[0])

def gcd(a,b):
    a,b = max(a,b),min(a,b)
    while b:
        a,b = b,a%b
    return a
def lcm(a,b):
    gc = gcd(a,b)
    return a*b//gc

for i in cont:
    found = False
    l,r = [int(j) for j in i]
    if 2*l <= r:
        print(f"{l} {l*2}")
    else:
        print("-1 -1")
