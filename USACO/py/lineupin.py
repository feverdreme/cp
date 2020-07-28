from itertools import permutations as perm

f= open('lineup.in','r+')
cont = f.readlines()
f.close()
cont = [i.rstrip('\n') for i in cont]
names = ['Bessie', 'Buttercup', 'Belinda', 'Beatrice', 'Bella', 'Blue', 'Betsy', 'Sue']

#get all brutes
brute = list((perm(names)))
brute.sort()

#interpret the information in the file
cont.pop(0)
cont = [i.split() for i in cont]
for i in cont:
    for j in range(4):
        i.pop(1)

#make every order a string with teh things
#for every ordering, concatenate
newbrute = []
for i in brute:
    temp = ''
    for j in i:
        temp += j + ' '
    temp = temp[:-1]
    newbrute.append(temp)
brute = newbrute
#for every list alphabetically, check if everything is next to each other
found = False
ans = ''
for ord in brute:
    for pair in cont:
        #now create the parings
        temp1 = pair[0] + ' ' + pair[1]
        temp2 = pair[1] + ' ' + pair[0]

        allcorrect = True
        if (temp1 in ord or temp2 in ord) and allcorrect:
            pass
        else:
            allcorrect = False
    if allcorrect:
        print(ord)
        break
print(cont)
