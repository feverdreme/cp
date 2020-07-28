field = {}
disp = []
temp = []
#generate board with input
#dim = input()
dim = 25 #can comment this out
for i in range(0,dim):
    temp.append(0)
    for j in range(0,dim):
        field.update({(i,j):0})
for i in range(0,dim):
    disp.append(temp)
#print(field)
living = [[1,3],
          [5,14],
          [8,19],
          [13,6]
]
def intolist(x):
    global field,disp
    for i in range(0,dim):
        for j in range(0,dim):
            tlist = disp[i]
            tlist[j] = field[(i,j)]
            disp[i] = tlist
    return disp
def addliving(x):
    global field
    #x is living
    for lis in x:
        field[(lis[0],lis[1])] = 1
def checkall(i,j):
    count = 0
    for dx in range(-1,2):
        for dy in range(-1,2):
            try:
                if field[(i+dx,j+dy)]:
                    count1 += 1
            except:
                pass
    if (field[(i,j)] and count < 4 and count > 1) or count == 3 and not field[(i,j)]:
        return 1
    else:
        return 0
def iterate():
    global dim
    #decode this for temp
    edit = dict(field)
    #for every one of those iterate it
    for i in range(0,dim):
        for j in range(0,dim):
            edit[(i,j)] = checkall(i,j)
addliving(living)
print(intolist(field))
