f= open('blist.in','r+')
cont = f.readlines()
f.close()
cont = [i.strip('\n').split() for i in cont]
cont.pop(0)
#get max and min
temp = [99999,0]
for i in cont:
    for j in range(2):
        temp[0] = min(temp[0],int(i[j]))
        temp[1] = max(temp[1],int(i[j]))
sim = []
for i in range(temp[1]+1):
    sim.append(0)
for i in cont:
    for j in range(3):
        i[j] = int(i[j])
for i in cont:
    for j in range(i[0],i[1]):
        sim[j] = sim[j] + i[2]
f=open('blist.out','w+')
f.write(str(max(sim)))
