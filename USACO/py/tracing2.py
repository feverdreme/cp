f= open('tracing.in','r+')
cont = f.readlines()
f.close()
cont = [i.rstrip('\n').split() for i in cont]
N,T = [int(i) for i in cont.pop(0)]
inf = [int(i) for i in cont.pop(0)[0]]
cont = [[int(i[j]) for j in range(3)] for i in cont]
cont = sorted([i[1:] + i[:1] for i in cont])

ans = [0,9999999,0]
#x - number of pos p0
#y - smallest K
#z - max K

def simulate(gK,gP0):
    empty = [0 for i in range(N)]
    for i in cont:
        res = (empty[i[1]-1] or empty[i[2]-1])
        if (i[1] == gP0 or i[2] == gP0):
            if gK != 0:
                gK -= 1
                empty[i[1]-1], empty[i[2]-1] = [res,res]
        else:
            empty[i[1]-1], empty[i[2]-1] = [res,res]
    if empty == inf:
        return True
    else:
        return False

for guessK in range(0,T+1):
    #if we get to t, then we are inf, but not right now

    for guessP0 in [i for i in range(N) if inf[i] == 1]:
        if simulate(guessK,guessP0+1):
            #update the vals
            ans[0] += 1
            ans[1] = min(ans[1],guessK)
            ans[2] = max(ans[2],guessK)
