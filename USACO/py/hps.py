from itertools import permutations as perm

f= open('hps.in','r+')
cont = f.readlines()
f.close()
cont = [i.strip('\n').split() for i in cont]
cont.pop(0)
cont = [[int(i[0]), int(i[1])] for i in cont]

#remove teh ties
for i in cont:
    if i[0] == i[1]:
        cont.remove(i)

def play(p1,p2):
    if (p1 == 'r' and p2 == 's') or (p1 == 's' and p2 == 'p') or (p1 == 'p' and p2 == 'r'):
        return True
    else:
        return False
#guess teh rock paper scissors
#thsi will be the format rock,paper,scissor
maxcount = 0
template = ['r','p','s']
for i in perm([1,2,3]):
    count = 0
    #create dict for values
    vals = {}
    #for every thing assign
    for j in range(3):
        vals.update({i[j] : template[j]})
    #now run through every game
    for j in cont:
        if play(vals[j[0]],vals[j[1]]):
            count += 1
    maxcount = max(maxcount,count)
f= open('hps.out','w+')
f.write(str(maxcount))
