f= open('buckets.in','r+')
cont = f.readlines()
f.close()
cont = [i.strip('\n') for i in cont]

lcoor = 0
bcoor = 0
rcoor = 0
for i in range(10):
    for j in range(10):
        coor = cont[i][j]
        if coor == 'L':
            lcoor = (i,j)
        elif coor == 'B':
            bcoor = (i,j)
        elif coor == 'R':
            rcoor = (i,j)

ret = abs(lcoor[0]-bcoor[0])+ abs(lcoor[1]-bcoor[1]) - 1
#check if their x values are the same
if (lcoor[0] == bcoor[0] and bcoor[0] == rcoor[0])vor (lcoor[1] == bcoor[1] and bcoor[1] == rcoor[1]):
    ret += 2
f= open('buckets.out','w+')
f.write(str(ret))
