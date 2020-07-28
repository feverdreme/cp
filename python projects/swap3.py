f= open('swap.in','r+')
cont = f.readlines()
f.close()
cont = [i.strip('\n').split() for i in cont]
N,M,K = cont.pop(0)
N,M,K = int(N),int(M),int(K)
cows = [i for i in range(1,N+1)]

for i in cont:
    i[0] = int(i[0])
    i[1] = int(i[1])

def swap():
    global cows,cont
    for swp in cont:
        a,b= swp[0]-1,swp[1]-1
        cows = cows[:a] + cows[a:b+1][::-1] + cows[b+1:]

iter = list(cows)
swap()
iter,cows = cows,iter
copp = list(cows)

cop = list(cows)
def allswap():
    global iter,cows,cop
    for i in range(N):
        cows[i] = cop[iter[i]-1]

count =1
cows = list(copp)
allswap()

maxre = False

while copp != cows and count < K:
    allswap()
    count += 1
if K == count:
    maxre = True

cows = list(copp)

if not maxre:
    for i in range(K % count):
        allswap()
else:
    for i in range(K):
        allswap()

ret = ''
for i in cows:
    ret += str(i) + '\n'
f= open('swap.out','w+')
f.write(ret)
f.close()
