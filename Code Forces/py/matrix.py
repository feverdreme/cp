# import fileinput
# cont = []
# for line in fileinput.input():
#     cont.append(line)
import sys
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
numTests = int(cont.pop(0)[0])
#first we split the thing up
ind = 0
newCont = []

for i in range(numTests):
    n = int(cont[0][0])
    newCont.append(cont[:n+1])
    cont = cont[n+1:]

ans = []

for case in newCont:
    n,m = case.pop(0)
    n,m = int(n),int(m)
    for i in range(n):
        for j in range(m):
            case[i][j] = int(case[i][j])
    #search through every row
    numRows,numCols = 0,0
    for i in case:
        if 1 in i:
            numRows += 1
    #search through numCols
    for colInd in range(m):
        for i in range(n):
            if case[i][colInd] == 1:
                numCols += 1
                break
    numRows = n - numRows
    numCols = m - numCols
    ans.append(min(numRows,numCols))

for i in ans:
    if i %2 == 0:
        print('Vivek')
    else:
        print('Ashish')
