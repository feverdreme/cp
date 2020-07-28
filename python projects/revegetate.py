f= open('revegetate.in','r+')
cont = f.readlines()
f.close()
cont = [i.strip('\n').split() for i in cont]
for i in cont:
    i[0] = int(i[0])
    i[1] = int(i[1])
N,M = cont.pop(0)

"""
    first we jsut iterate through everything and find possible color
    then we store the pairs in another lsit
        by storing all 4 colors for everything
        then popping for everytime we use one
    so then it jsut evnes out
"""

x = [None] * (N+1)
used = list(x)

#now iterate and assign
for i in cont:
    #now check
    if x[i[0]] == None and x[i[1]] == None:
        x[i[0]],x[i[1]] = 'A','B'
        used[i[0]].append('A')
        used[i[1]].append('B')
    elif x[i[0]] != None:
        #find something thats not used and not i[0]
        
