f=open('triangles.in','r+')
cont = f.readlines()
f.close()
n = int(cont.pop(0)[0])
points = [i.strip('\n').split() for i in cont]
for i in points:
    for j in range(2):
        i[j] = int(i[j])
sx = sorted(points)
sy = [i for i in sorted(points[::-1])]
ret = 0
#loop thorugh every x, get their y, and then find the indexs whch correspond
for ind,coor in enumerate(sx):
    #keep traversing the x until you stop
    trackedind = ind
    x,y = coor
    sumx,sumy = 0,0
    #this gets the sum of y
    while sx[trackedind][0] == x:
        sumy += abs(sx[trackedind][1] - y)
        trackedind += 1
    #get the sum of x
    trackedind = sy.index(y)
    while sy[trackedind] == y:
        sumx += abs(sy[trackedind][1] - x)
    ret += sumx * sumy
print(ret)
    #get the sumx * sumy
