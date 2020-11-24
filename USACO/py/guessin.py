f= open('guess.in','r+')
cont = f.readlines()
f.close()
cont.pop(0)
cont = [i.strip('\n').split() for i in cont]
for i in cont:
    i.pop(0)
    i.pop(0)

maxm = 0
for ind1 in cont:
    for ind2 in cont:
        if ind1 != ind2:
            #proceed
            maxm = max(maxm, len(ind1+ind2) - len(set(ind1+ind2)))
#go through every combination
f= open('guess.out','w+')
f.write(str(maxm + 1))
