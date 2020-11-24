import sys
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
numTests = int(cont.pop(0)[0])

nc = []
for i in range(numTests):
    nc.append(cont[:2])
    cont = cont[2:]

for i in nc:
    n,k = i.pop(0)
    n,k = int(n),int(k)
    aval = i[0][0]
    counts=  {}
    for j in sorted(list(set(aval))):
        counts.update({j:aval.count(j)})
    res = max(set(aval), key = aval.count)
    vals = counts.values()
    counts.pop(res)

    necklace = max(vals)
    #now go for efery distinct adn check
    for j in list(set(aval)):
        if j == res:continue
        if necklace / k == 1:
            #then the necklace is already perfect
            necklace += (counts[j] // 5)
        else:
            if counts[j] >= necklace:
                necklace *= 2
    print(necklace)
