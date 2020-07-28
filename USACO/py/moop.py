f= open('moop.in','r+')
cont = f.readlines()
f.close()
cont = [i.rstrip('\n').split() for i in cont]
N = int(cont.pop(0)[0])
for i in cont:
    for j in range(2):
        i[j] = int(i[j])
cont.sort()

ind = 1
while ind != len(cont):
    prev = cont[ind]
    if prev[0] <= cont[0] and prev[1] <= cont[1]:
        cont.pop(ind)
f = open('moop.out','w+')
f.write(str(len(cont)))
