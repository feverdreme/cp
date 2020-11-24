f= open('sleepy.in','r+')
cont= f.readlines()
f.close()
cont = [i.rstrip('\n') for i in cont]
N = int(cont.pop(0))
cont = cont[0].split()
cont = [int(i) for i in cont]

#reverses the string
#find the min prefix where its sorted
maxlen = 0

for index in range(1,N+1):

    temp = list(cont[N-index:])
    temp2 = list(temp)
    temp2.sort()
    if temp == temp2:
        maxlen += 1
# """
#     ok so we want to get the last suffix,
#     reverse teh string
#     what do we want: for it to go in increasing order
#
# """
f= open('sleepy.out','w+')
f.write(str(N-maxlen))
