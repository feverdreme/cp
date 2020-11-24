f= open('moocrypt.in','r+')
cont = f.readlines()
f.close()
cont = [i.strip('\n').split() for i in cont]
N,M = cont.pop(0)
N,M = int(N),int(M)
cont = [i[0] for i in cont]
alp = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

def search(l1='M',l2='N'):
    global cont,N,M
    #find coordinates of the M
    coors = []
    for i in range(N):
        for j in range(M):
            if cont[i][j] == l1:
                coors.append((i,j))

    #look for l2
    for coor in coors:
        #look horizonally
