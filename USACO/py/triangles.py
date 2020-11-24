from math import sqrt

f= open('triangles.in','r+')
cont = f.readlines()
f.close()
cont = [i.strip('\n').split() for i in cont]
cont.pop(0)
coors = [[int(i[0]) , int(i[1])] for i in cont]

ret = 0
#first pick through every point and check if the conditions are met
for i in coors:
    for j in coors:
        for k in coors:
            if i!=j and j!=k and i!=k:
                #now we ifnd if they satisfy the conditions
                #we will merge with with the if statemtn later one maybe
                if len({i[0] for i in [i,j,k]}) == 2 and len({i[1] for i in [i,j,k]}) == 2:
                    #we need to calculate the area somehow
                    #we can use teh semiperimeter formula
                    d1 = sqrt( (i[0]-j[0])**2 + (i[1]-j[1])**2 )
                    d2 = sqrt( (k[0]-j[0])**2 + (k[1]-j[1])**2 )
                    d3 = sqrt( (i[0]-k[0])**2 + (i[1]-k[1])**2 )
                    ret = max(ret, d1 * d2 * d3 / max(d1,d2,d3))
f= open('triangles.out','w+')
f.write(str(int(ret)))
