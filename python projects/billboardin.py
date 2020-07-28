f = open('billboard.in','r+')
cont = f.readlines()
for x in range(3):
    cont[x] = cont[x].rstrip('\n').split()
#for every case
print cont[0][3]
