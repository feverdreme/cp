f= open('hps.in','r+')
cont = f.readlines()
f.close()
cont = [i.rstrip('\n') for i in cont]
N = int(cont.pop(0))

"""
    first we want the alt values, so where they alternate
    then we get the lengths at which they alternate,
    and the alternate values

    then we pick a starting point, then a place to switch
    then we run through that evaulauting for every thing until teh switch then after
    then we do the max
"""
#vars
altind = [0]
altlens = []
altvals = [cont[0]]
maps = 0
choose = ['H','P','S']
maxwin = 0

#get the alt values and alt inds
prev = cont[0]
for i in range(N):
    if cont[i] != prev:
        altind.append(i)
        altvals.append(cont[i])
        prev = cont[i]
#get the alt lens
altlens = [altind[i+1] - altind[i] for i in range(len(altind)-1)]
altlens.append(N - altind[-1])
#assign the maps
maps = zip(altvals,altlens)
#now do the play func
def play(p1,p2):
    if (p1 == 'H' and p2 == 'S') or (p1 == 'S' and p2 == 'P') or (p1 == 'P' and p2 == 'H'):
        return True
    else:
        return False
#now run the simulation
for first in choose:
    for swapind in range(len(maps)):
        #now run through everything up to it
        win = 0
        for before in range(swapind):
            win += play(first,maps[swapind][0]) * maps[swapind][1]
        for after in range(swapind,len(maps)):
            win += 
