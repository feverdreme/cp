f= open('gymnastics.in','r+')
cont = f.readlines()
f.close()
cont = [i.rstrip('\n').split() for i in cont]
K = int(cont[0][0])
N = int(cont[0][1])
cont.pop(0)

for i in range(K):
    for j in range(N):
        cont[i][j] = int(cont[i][j])

#look through every person, N
#then look if they are ahead the next person
#look for every one, pair with teh ones that they are beter than,
#then check for teh dictionary, if they have a count = K
winners = []
for round in cont:
    #this looks through every roudn wiht tehir index
    for scan in range(N):
        for length in range(1,N-scan):
            #looks after these are all indexes
            winners.append((round[scan],round[scan+length]))

#for this, you look for every combination, and see if the count is something
count = 0
for i in range(1,N+1):
    for j in range(1,N+1):
        if i!=j and winners.count((i,j)) == K:
            count += 1
f=open('gymnastics.out','w+')
f.write(str(count))
