import sys
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
numTests = int(cont.pop(0)[0])

nc = []
for i in range(numTests):
    nc.append(cont[:2])
    cont = cont[2:]

for l in nc:
    lenn = int(l[0][0])
    t = [int(j) for j in l[1]]
    numEven = len([i for i in t if i%2 == 0])

    if lenn % 2 == 0:
        #even
        if numEven == lenn / 2:
            numIncorrect = 0
            for ind,i in enumerate(t):
                if i%2 != ind%2:numIncorrect += 1
            print(numIncorrect//2)
        else:
            #impossible
            print(-1)
    else:
        #odd
        if numEven == lenn - numEven + 1:
            #possible
            numIncorrect = 0
            for ind,i in enumerate(t):
                if i%2 != ind%2:numIncorrect += 1
            print(numIncorrect//2)
        else:
            print(-1)
