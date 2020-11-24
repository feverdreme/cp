from math import floor as fl

f= open('socdist1.in','r+')
cont = f.readlines()
f.close()
cont = [i.strip('\n') for i in cont]
cont = [int(i) for i in cont]
N = cont.pop(0)
cont = str(cont[0])

"""
    traverse the list, find all the blocks of zeros then add 1
    then find the max
    floor(max/2) would be our answer

    but we want TWO cows, so we need to insert them at there so we do two iterations

    first, we get the lens, and split them up as equally
    then get get anotehr max lens and split
    then we get our answer
"""
#now loop again
#do a first iterations
for i in range(2):
    lens = cont.split('1')
    #Ok lets do this more methodically

    #get the index of the max
    ind = cont.index(max(lens))
    #get the ind mid
    ms = list(max(lens))
    print (ms)
    ms[int(len(ms)/2)] = '1'
    ms = ''.join(ms)
    ind2 = ms.index('1')
    #now take the cont and insert
    cont = list(cont)
    cont[ind+ind2] = '1'
    cont = ''.join(cont)

lens = cont.split('1')

f= open('socdist1.out','w+')
f.write(str(len(max(lens))))
f.close()
