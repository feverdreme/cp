f= open('socdist2.in','r+')
cont = f.readlines()
f.close()
for i in range(len(cont)):
    cont[i] = cont[i].rstrip('\n').split()
N = cont[0][0]
cont.pop(0)
#get infected and ninf
inf = []
ninf = []
for i in cont:
    if int(i[1]):
        inf.append(int(i[0]))
    else:
        ninf.append(int(i[0]))
dict = {int(i[0]):int(i[1]) for i in cont}
allr = inf+ninf
allr.sort()
#find the max radius
maxR = []
for i in inf:
    for j in ninf:
        maxR.append(abs(i-j))
maxR = min(maxR) - 1
#look for the blocks
count = 0
inf.sort()
for i in range(len(inf)):
    if i != len(inf)-1:
        if inf[i+1]-inf[i] > maxR:
            count += 1
print(count)
f= open('socdist2.out','w+')
f.write(str(count+1))
f.close()
