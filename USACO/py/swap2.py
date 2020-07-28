f= open('swap.in','r+')
cont = f.readlines()
f.close()
cont = [i.strip('\n').split() for i in cont]
N,K = cont.pop(0)
N,K = int(N),int(K)
cows = [i for i in range(1,N+1)]
cowscheck = list(cows)
#ok damn i hate this
#first we need to find the cycle
a1,a2 = cont.pop(0)
b1,b2 = cont.pop(0)
a1,a2,b1,b2 = int(a1)-1,int(a2)-1,int(b1)-1,int(b2)-1

def swap():
    global cows,a1,a2,b1,b2
    cows = cows[:a1] + cows[a1:a2+1][::-1] + cows[a2+1:]
    cows = cows[:b1] + cows[b1:b2+1][::-1] + cows[b2+1:]
"""
1,2,3,4,5,6,7

"""

#find the ammount of iteratiosn till same
count = 1
swap()
while cows != cowscheck:
    count += 1
    swap()
for i in range(K % count):
    swap()

f= open('swap.out','w+')
ret = ''
for i in cows:
    ret += str(i) + '\n'

f.write(ret)
f.close()
