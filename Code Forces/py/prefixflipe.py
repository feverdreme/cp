import sys
from math import floor as fl
from math import ceil as ce
from math import sqrt
cont = sys.stdin.readlines()
cont = [i.strip('\n') for i in cont]
num = int(cont.pop(0)[0])

def invert(string):
    ret = ''
    for i in string:
        if i == '1':
            ret += '0'
        else:
            ret += '1'
    return ret

def op(string,pos):
    tbf = ''
    ret = ''
    for ind,i in enumerate(string):
        if ind <= pos:
            #you flip it
            if i == '1':
                tbf += '0'
            else:
                tbf += '1'
        else:
            ret += i
    return tbf[::-1] + ret

for i in range(num):
    operations = []

    arr = cont[:3]
    cont = cont[3:]
    l = int(arr.pop(0))
    pointer = l-1
    a1,a2 = arr
    while pointer != -1:
        if a1[pointer] == a2[pointer]:
            pointer -= 1
            continue

        #there is a problem
        if a1[0] != a2[pointer]:
            #this means we can just do a flip at the pointer location
            operations.append(pointer+1)
            a1 = op(a1,pointer)
            pointer -= 1
        else:
            #this means that the two match which means we have to find it

            operations.append(1)
            a1 = op(a1,0)

            operations.append(pointer+1)
            a1 = op(a1,pointer)
            pointer -= 1

    ret = str(len(operations))
    for j in operations:
        ret += f" {j}"
    print(a1,a2)
