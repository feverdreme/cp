f= open('socdist2.in',"r+")
contents = f.readlines()
f.close()
N = int(contents[0].rstrip("\n"))
contents.pop(0)
inf = []
ninf = []
#format
for x in range(0,N):
    contents[x] = contents[x].rstrip("\n").split()
#get infect and not
for x in range(0,N):
    if contents[x][1] == "1":
        inf.append(contents[x])
    else:
        ninf.append(contents[x])
#find min radius
minr = int(1E6)
for infect in inf:
    for ninfect in ninf:
        dist = abs(int(infect[0])-int(ninfect[0]))
        if dist < minr:
            minr = dist - 1
#finddist between infected
#format them
nc = []
for x in range(0,N):
    nc.append(int(contents[x][0]))
nc.sort()
#dist
di = []
for x in range(0,N-1):
    di.append(nc[x+1] - nc[x])
#def sum of all in group
def su(x):
    sum = 0
    for z in x:
        sum += z
    return sum
#brute
numcows = 0
pos = 0
ldi= len(di)
while pos < ldi:
    sd = di[pos]
    #print(pos)
    itworks = False
    while sd <= 2 * minr and pos < ldi-1:
        pos += 1
        itworks = True
        sd += di[pos]
    if itworks == False:
        pos += 1
    numcows +=1
#print(numcows)
#[2, 3, 1, 3, 5]
#write
f= open('socdist2.out','w+')
f.write(str(numcows))
f.close()
