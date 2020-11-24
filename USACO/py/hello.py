f= open("lifeguards.in","r+")
cont = f.readlines()
N = int(cont[0])
del cont[0]
f.close()
newcont = []

#removes the /n
for x in range(0,len(cont)):
    cont[x] = cont[x].rstrip("\n")
    cont[x] = cont[x].split()
    newcont.append(int(cont[x][0]))
    newcont.append(int(cont[x][1]))

#do rem for every item
maxtime = 0
for rem in range(0,len(cont)):
    #fire one of them
    tarr = []
    for x in newcont:
        tarr.append(x)
    tarr.pop(2 * rem + 1)
    tarr.pop(2 * rem)
    #now computer all time taken
    print(tarr)
