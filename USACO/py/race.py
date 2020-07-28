f=open("race.in",'r+')
cont = f.readlines()
f.close()
cont = [i.strip('\n').split() for i in cont]

k,n = cont.pop(0)
k,n = int(k),int(n)
cont = [int(i[0]) for i in cont]

f=open('race.out','w+')
for maxX in cont:
    #we want to test the speeds until we get an optimal solution
    #bfs could work
    stack = [[0,0,0]]
    #queue element is [dist,speed,time]
    while True:
        t = stack.pop()
        if t[0] >= k:
            if t[1] <= maxX and t[0] == k:
                print(t[2]-1)
                break
        else:
            if t[0] >= 2:
                stack.append([t[0]+t[1]-1, t[1]-1, t[2]+1])
            if t[0] >= 1:
                stack.append([t[0]+t[1], t[1], t[2]+1])
            if not (t[1] > 2 * maxX and t[0] >= k//2) and not(t[1] <= .5*(maxX)*(maxX+1)):
                stack.append([t[0]+t[1]+1, t[1]+1, t[2]+1])

f.close()
