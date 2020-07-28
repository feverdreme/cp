f= open('shell.in','r+')
cont = f.readlines()
f.close()
cont.pop(0)
cont=[i.strip('\n').split() for i in cont]
for i in range(len(cont)):
    for j in range(3):
        cont[i][j] = int(cont[i][j])-1

maxpts = 0
for target in range(3):
    rock = [False,False,False]
    rock[target] = True
    #now cycle through every swapping
    pts=0
    for swaps in cont:
        rock[swaps[0]],rock[swaps[1]] = rock[swaps[1]],rock[swaps[0]]
        if rock[swaps[2]]:
            pts += 1
    maxpts = max(maxpts,pts)
f=open('shell.out','w+')
f.write(str(maxpts))
