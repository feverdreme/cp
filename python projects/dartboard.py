from random import random
from sys import setrecursionlimit as srecur
srecur(10**9)
#do until terminated
def throw(accu,num = 1,rad = 1):
    #get two coordinates
    x = random()
    y = random()
    dst = (1-accu)*((x**2 + y**2) ** .5)
    #check if in circle
    if dst <= rad:
        newrad = (rad**2 - dst**2) ** .5
        throw(accu,num+1,newrad)
    else:
        global runningtotal
        runningtotal += num

#do the graph
avgs = {}
acdepth = 900
for x in range(1,acdepth):
    runningtotal = 0
    actaccu = x / float(10 ** len(str(acdepth)))
    for times in range(10**2):
        throw(actaccu,1,1)
    ag = runningtotal / acdepth
    avgs.update({actaccu: ag})

for x in range(1,acdepth):
    print(avgs[x / float(10** len(str(acdepth)))])
