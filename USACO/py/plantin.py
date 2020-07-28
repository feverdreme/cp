f= open('planting.in','r+')
cont = f.readlines()
f.close()
cont.pop(0)
cont = [i.rstrip('\n').split() for i in cont]
for i in cont:
    i[0] = int(i[0])
    i[1] = int(i[1])

#we want to count everything
#best way is to use lists
#the index is the sort
look = {}
for i in cont:
    #first we assign
    look[i[0]] = 0
    look[i[1]] = 0
#now do the count
for i in cont:
    #now we count
    look[i[0]] += 1
    look[i[1]] += 1
f= open('planting.out','w+')

f.write(str(max(look.values())+1))
