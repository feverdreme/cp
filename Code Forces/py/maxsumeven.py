import sys
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
numTests = int(cont.pop(0)[0])
nc = []
for i in range(numTests):
    nc.append([int(i) for i in cont[1]])
    cont = cont[2:]
cont = nc

# def getOdd(arr):
#     # print([i for ind,i in enumerate(arr[0]) if ind%2 == 1])
#     return sum([i for ind,i in enumerate(arr) if ind%2 == 1])
#
# def getEven(arr):
#     print(arr,'-')
#     return sum([i for ind, i in enumerate(arr) if ind%2 == 0])

def recur(bitmask,arr,left=0,right=-1):
    print(~int(bitmask))

for i in cont:
    bitmask = '10' * (len(i)//2) + '1' * (len(i)%2)
    x = recur(bitmask,i)
