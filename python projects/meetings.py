f= open('meetings.in','r+')
cont = f.readlines()
f.close()
cont = [i.strip('\n').split() for i in cont]
N,L = cont.pop(0)
N,L = int(N),int(L)
for i in cont:
    for j in range(3):
        i[j] = int(i[j])
    i[0],i[1]=i[1],i[0]

count = 0
totalWeight = sum([i[1] for i in cont])
cont.sort()
run = 0
#x w d
numNeg = 0
numPos = 0
pos = []
neg = []
for i in cont:
    if i[2] == 1:
        numPos += 1
        pos.append(i)

    else:
        numNeg += 1
        neg.append(i)

finish = []

# t and w
for i in range(numNeg):
    finish.append([neg[i][0],cont[i][1]])

pos = pos[::-1]
cont = cont[::-1]
for i in range(numPos):
    finish.append([L-pos[i][0] , cont[i][1]])
finish.sort()

for ind,i in enumerate(finish):
    run += i[1]
    if run >= totalWeight / 2:
        count = ind

#now determine the number of collisions
cont = cont[::-1]
collisions = []

def check():
    global collisions,cont
    if cont != [] and cont[0][2] == -1:
        cont.pop(0)
    if cont != [] and cont[-1][2] == 1:
        cont.pop(-1)

    for i in range(N):
        if i == N-1:break
        if cont[i][2] == 1 and cont[i+1][2] == -1:
            collisions.append([])
