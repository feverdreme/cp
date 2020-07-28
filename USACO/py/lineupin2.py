from itertools import permutations as perm

f= open('lineup.in','r+')
cont = f.readlines()
f.close()
cont.pop(0)
cont = [i.rstrip('\n').split() for i in cont]
for i in cont:
    for x in range(4):
        i.pop(1)

names = ['Bessie', 'Buttercup', 'Belinda', 'Beatrice', 'Bella', 'Blue', 'Betsy', 'Sue']
brute = [i for i in perm(names)]
brute.sort()
#make every tuple a string
newbrute = []
for i in brute:
    temp= ''
    for j in i:
        temp += j + ' '
    newbrute.append(temp)
brute = newbrute

#check for every order, and pair
ans = 0
for ord in brute:
    allcorrect = True
    for pair in cont:
        #make the pair both and string
        temp1 = pair[0] + ' ' + pair[1]
        temp2 = pair[1] + ' ' + pair[0]

        if (temp1 in ord or temp2 in ord) and allcorrect:
            pass
        else:
            allcorrect = False
    if allcorrect:
        ans = ord
        break

ans = ans.split()
f= open('lineup.out','w+')
for i in ans:
    f.write(i + '\n')
