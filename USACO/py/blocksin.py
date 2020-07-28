f= open('blocks.in','r+')
cont = f.readlines()
for x in range(len(cont)):
    cont[x] = cont[x].rstrip('\n').split()
N = cont[0]
cont.pop(0)
alphabet = 'abcdefghijklmnopqrstuvwxyz'
dictCount = {i : 0 for i in alphabet}
emptyD = dict(dictCount)
for board in cont:
    #do for both
    #both sides
    temps = [dict(emptyD),dict(emptyD)]
    for x in range(2):
        #each letter in the board
        for letters in board[x]:
            temps[x].update({letters:temps[x].get(letters)+1})
    #get the maxes
    for maxl in alphabet:
        dictCount.update({maxl: max(temps[0].get(maxl),temps[1].get(maxl))})
print(dictCount)
