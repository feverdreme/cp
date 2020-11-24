import sys
from math import floor as fl
from math import ceil as ce
from math import sqrt
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
num = int(cont.pop(0)[0])

def arrtoint(arr):
    return [int(i) for i in arr]

for i in range(num):
    arr = cont[:2]
    cont = cont[2:]
    l = int(arr.pop(0)[0])
    arr = arrtoint(arr[0])

    #edge cases
    if len(arr) == 1:
        print("First")
    elif arr.count(1) == l:
        if l % 2 == 1:
            print("First")
        else:
            print("Second")
    elif arr.count(1) == 0:
        print("First")
    else:
        #edge cases are done

        arr.pop()

        if set(arr) == {1}:
            if l % 2 == 1:
                print("First")
            else:
                print("Second")
            continue
        #if the number of leading ones is eve, first
        #else, second

        aind = arr.index(next(filter(lambda x: x>1, arr)))
        if aind % 2 == 0:
            print("First")
        else:
            print("Second")
