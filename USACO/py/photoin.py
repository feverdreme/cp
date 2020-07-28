f= open('photo.in','r+')
cont = f.readlines()
f.close()
cont = [i.rstrip('\n') for i in cont]

cont = cont[1].split()
cont = [int(i) for i in cont]

for guess in range(cont[0] + 1):
    pass
