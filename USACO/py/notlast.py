#Bessie, Elsie, Daisy, Gertie, Annabelle, Maggie, and Henrietta
f=open('notlast.in','r+')
cont = f.readlines()
f.close()
cont = [i.strip('\n') for i in cont]
cont.pop(0)
cont = [i.split() for i in cont]
cows = {'Bessie':0, 'Elsie':0, 'Daisy':0, 'Gertie':0, 'Annabelle':0, 'Maggie':0, 'Henrietta':0}
#iterate through all milkings
for i in cont:
    cows[i[0]] += int(i[1])
cont = cows.items()
cont = [list(i)[::-1] for i in cont]
#find the second
cont.sort()
"""
    first we create  separate thing
    no duplicates
    get the second item
    go to the original find the count
    then consult the list again
"""
dupe = [i[0] for i in cont]
nodupe = list(set(dupe))
nodupe.sort()
if len(nodupe) != 1:
    secondmost = nodupe[1]
    lentrue = True
else:
    lentrue = False
    ret = 'Tie'
if lentrue:
    secondcount = dupe.count(secondmost)
    ret = 0
    if secondcount == 1:
        #if there are no duplicates
        for i in cont:
            if i[0] == secondmost:
                ret = i[1]
    else:
        ret = 'Tie'
f=open('notlast.out','w+')
f.write(str(ret))
