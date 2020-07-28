f= open('cowsignal.in','r+')
cont = f.readlines()
f.close()
cont = [i.strip('\n') for i in cont]
cont[0] = cont[0].split()
m,n,k = cont[0]
m,n,k = int(m),int(n),int(k)
cont.pop(0)
#now create a new list but individually indexed
ret = []
for i in range(m*k):
    temp = []
    for j in range(n*k):
        temp.append(0)
    ret.append(temp)

#now scan through the contents and assign
# with some i,j do ki,kj ki+1,kj, ki,kj+1 ki+1,kj+1
for i in range(m):
    for j in range(n):
        for z in range(k):
            for x in range(k):
                ret[k*i+z][k*j+x] = cont[i][j]
output = ''
for i in range(m*k):
    temp = ''
    for j in range(n*k):
        temp += str(ret[i][j])
    output += temp + '\n'
f= open('cowsignal.out','w+')
f.write(output)
