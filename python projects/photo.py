f= open('photo.in','r+')
cont = f.readlines()
f.close()
cont = [i.strip('\n').split() for i in cont]
N = int(cont.pop(0)[0])
cont = [int(i) for i in cont[0]]

"""
    first check do teh check if its finished
    then check if it has no dupes
    //then check that the max and mins are correct

    then take the current number of the runn, then tke next index
    then subtract, and add

    tehn keep looping with more indicies

    exp
    [1,4,5,7]
"""

def recur(ind=0,runn = []):
    global N, cont
    if ind == N:
        return runn
    #now do teh check
    elif len(set(runn)) != len(runn):
        return
    else:
        #do the thing
        temp = runn[-1] - cont[ind]
