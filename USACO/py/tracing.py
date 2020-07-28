f= open('tracing.in','r+')
cont = f.readlines()
f.close()
cont = [i.strip('\n').split() for i in cont]
N = int(cont[0][0])
T = int(cont[0][1])
K = int(cont[1][0])
cont.pop(0)
cont.pop(0)
for i in cont:
    for j in range(3):
        i[j] = int(i[j])
cont.sort()

#make the lsit of cows
K = [int(i) for i in str(K)]
#we dont care about time
for i in cont:
    i.pop(0)

#define vars
maxk = 0
mink = 99999999
numpos = 0

#guess a patient
#gues a K

"""
    first we guess a patient to be patient 0
    then we evaluate the list with a guessed K
        simply iterate through all steps adn keep track of hanshakes
    then if it works out,
    we update the vars
    if K = 251, then make it infinity
"""
shakes = cont

for gp in range(1,N+1):
    for gk in range(250+1):
        #now being the trial
        inf = list(K)
        shakedone = 0
        #iterate through the list
        for shake in shakes:
            #if one of them is infected check the K
            if shakedone < gk:
                #do the thing
                shake[0],shake[1] = (shake[0] or shake[1]),(shake[0] or shake[1])
                shakedone += 1
            else:
                #don't do the thing, evalutate adn make sure conditions
                #eval
                pass
