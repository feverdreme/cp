f= open('shell.in','r+')
cont = f.readlines()
f.close()
cont = [i.strip('\n').split() for i in cont]
cont.pop(0)
for i in cont:
    for j in range(3):
        i[j] = int(i[j])
maxc = 0
for peb in range(3):
    board = [False,False,False]
    board[peb] = True
    count = 0
    #now we do the swaps
    for i in cont:
        board[i[0]-1],board[i[1]-1] = board[i[1]-1],board[i[0]-1]
        if board[i[2]-1]:
            count += 1
    maxc = max(maxc,count)
f= open('shell.out','w+')
f.write(str(maxc))
