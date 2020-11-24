import sys
from math import ceil as ce
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
numTests = int(cont.pop(0)[0])

tests = []
for i in range(numTests):
    n = int(cont[0][0])
    tests.append(cont[:n+1])
    cont = cont[n+1:]

def solve(n,m,matrix):
    count = [0]*m
    t = max(m,n)
    #swap them when needed acording to tInd
    if t == n: matrix = list(zip(*matrix))
    # print(matrix)

    for step in range(ce(m/2)+1):
        temp = [matrix[i][step-i] for i in range(step+1) if i < n]
        temp2 = [[m-step-i,i] for i in range(step+1) if i < n]
        print(temp2,step)
        # temp2 = [[step-i,m-step-1] for i in range(step+1)]
        # print(temp2)

        # temp += temp2
        # print(temp,f' {m},{n}')
    #     if '0' in temp and '1' in temp:
    #         count[m-1] = min(temp.index('0'),temp.index('1'))
    # print(count)


for i in tests:
    n,m = i[0]
    n,m = int(n),int(m)
    solve(n,m,i[1:])
