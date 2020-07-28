f= open('milkorder.in','r+')
cont = f.readlines()
f.close()
cont = [i.rstrip('\n').split() for i in cont]
for i in cont:
    for j in range(len(i)):
        i[j] = int(i[j])
N,M,K = cont.pop(0)
heir = cont.pop(0)
#first we make the array
order = []
for i in range(N+2):
    order.append(None)
#now assign for the order
for i in cont:
    order[i[1]] = i[0]
#then we build everybody else
#first if one of the assigned ones are in teh heirarchy
#if not, then we jsut put the next availible one
#if yes, then we build it
#remember, there will always be a solution

# we detect
isIn = False
for i in order:
    if i in heir:
        isIn = True

#now we do the thing
if isIn:
    #then we do the thing
    #find the index where it is found
    ind = heir
else:
    #hten we just find the next possible one
    ind = 1
    while order[ind] != None:
        ind += 1
    #then the ind+1 is the place

from math import factorial
x = factorial(100)
print x
