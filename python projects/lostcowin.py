f= open('lostcow.in','r+')
cont = f.readlines()
f.close()
cont = cont[0].rstrip('\n').split()
x = cont[0]
y = cont[1] - x
x = 0
dests = []
