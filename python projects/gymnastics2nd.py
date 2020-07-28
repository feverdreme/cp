f= open('gymnastics.in','r+')
cont = f.readlines()
f.close()
cont = [i.strip('\n').split() for i in cont]
K,N = cont.pop(0)
K,N = int(K),int(N)

"""
    first we look through every K trasinign session,
    do a linear scan getting the combinations in tuples
    find the count of tuples and do the thing
"""
all = []
for ses in cont:
    #now we loop through every index
    for start in range(N):
        for offset in range(1,N-start):
            all.append((ses[start],ses[start+offset]))
temp = list(set(all))
ret = 0
for i in temp:
    if all.count(i) == K:
        ret += 1
f= open('gymnastics.out','w+')
f.write(str(ret))
