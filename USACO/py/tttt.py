f= open('tttt.in','r+')
cont = f.readlines()
f.close()
board = [i.rstrip('\n') for i in cont]
#first do a scan of all horizontal
sing = []
two = []
#we want to keep track of all teams
for rowindex in range(3):
    x = list(set(board[rowindex]))
    if len(x) == 2:
        two.append(tuple(x))
    elif len(x) == 1:
        sing.append(x[0])
for colindex in range(3):
    x = list(set(board[i][colindex] for i in range(3)))
    if len(x) == 2:
        two.append(tuple(x))
    elif len(x) == 1:
        sing.append(x[0])
#now scna for diagonals
x = list(set(board[i][i] for i in range(3)))
if len(x) == 2:
    two.append(tuple(x))
elif len(x) == 1:
    sing.append(x[0])
#scan for second diagonal
x = list(set(board[2-i][i] for i in range(3)))
if len(x) == 2:
    two.append(tuple(x))
elif len(x) == 1:
    sing.append(x[0])

f = open('tttt.out','w+')
f.write('%d\n%d\n' % (len(set(sing)) , (len(set(two)))))
f.close()
