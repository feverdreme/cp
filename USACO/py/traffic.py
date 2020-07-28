f= open('traffic.in','r+')
cont = f.readlines()
f.close()
n = int(cont.pop(0)[0])
cont = [i.strip('\n').split() for i in cont]

ind = 0
curr = []
for i in cont:
    m1,m2 = int(i[1]),int(i[2])
    if i[0] == 'none':
        curr[0] = max(curr[0],m1)
        curr[1] = max(curr[1],m2)
    elif i[1] == 'on':
        curr[0] += min(m1,m2)
        curr[1] += max(m1,m2)
    else:
        curr[0] -= max(m1,m2)
        curr[1] -= min(m1,m2)
print(curr)
