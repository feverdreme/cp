f= open('square.in','r+')
cont = f.readlines()
f.close()
newcont = []
for x in range(0,2):
    cont[x] = cont[x].rstrip('\n')
    newcont.append(cont[x].split())
xc = []
yc = []
con = []
for i in newcont:
    for j in i:
        con.append(int(j))
for x in range(8):
    if x % 2:
        yc.append(con[x])
    else:
        xc.append(con[x])

f= open('square.out','w+')
f.write(str(max(max(xc)-min(xc),max(yc)-min(yc))**2))
