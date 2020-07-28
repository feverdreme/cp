from random import randint

rbCount = 0.0
bCount = 0
#do the thing
for depth in range(0,int(9E6)):
    isRed = False
    isBlack = False
    urns = [[0,0,0,0,1,1],[1,1,1,2,2,2]]
    rb1 = randint(0,5)
    if urns[randint(0,1)].pop(rb1) == 1:
        isRed = True
    secondurn = urns[randint(0,1)]
    if secondurn.pop(randint(0,len(secondurn)-1)) == 2:
        isBlack = True
    if isBlack:
        bCount += 1
        if isRed:
            rbCount += 1
print(rbCount / bCount)
