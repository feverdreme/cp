from math import floor as fl

f= open('moobuzz.in','r+')
cont = f.readlines()
f.close()

N = int(cont[0])

#x = N%8
#y = fl(N/8) * 15

ref = {1:1,2:2,3:4,4:7,5:8,6:11,7:13,0:14}

#print(y + ref[x])
f=open('moobuzz.out','w+')
f.write(str(fl(N/8) * 15 + ref[N%8]))

"""
    if we take the index and mod by 8, we get this index pattern
    1,2,m,4,m,m,7,8,m,m,11,m,13,14,m
    16,17,m,19,m,m,22,23,m,m,26,m,28,29,m

    then we can multiply teh N/8 int)) * 15 to get the height
    then add by the corresponding thing

    so the 9th number
    9%8 = 1
    floor(9/8) = 1
    15*1 + 1 = 16

    what if it is mod 8?
    then you either add my 0 or 14
    if it is 0, then it would be 14, we need EDGE CASE, but 0 would never happen

    if it is 16, then it would be
    16/15 = 1
    15+14 = 29
"""
