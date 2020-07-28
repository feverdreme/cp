import sys
from math import floor as fl
from math import ceil as ce
from math import sqrt
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
num = int(cont.pop(0)[0])

nc = []
for i in range(num):
    nc.append(cont[:2])
    cont = cont[2:]
cont = nc

def check(arr):
    bound = 0
    while len(arr) != 0:
        minn = min(arr)
        if not(arr[0] == minn or arr[-1] == minn):
            #^ if neither are the minimum
            return bound + arr.index(minn)
        else:
            #it is on one of them ends
            if arr[0] == minn:
                bound += 1
                arr.pop(0)
            else:
                arr.pop(-1)
    return True

for i in cont:
    n = i.pop(0)
    i = [int(j) for j in i[0]]


    """
    first we have some arr getting suffix,

    then check
        if error:
            find index, the suffix point is at that now
        else:
            we've found the answer
    this should run at most n^2, but mostly nlogn
    it reduces the checking of suffixes
    """

    suffixpoint = 0
    checkedVal = check(i[suffixpoint:])
    # this is saying that if the check is invalid
    while not(checkedVal is True):
        suffixpoint += checkedVal
        checkedVal = check(i[suffixpoint:])
        # print(suffixpoint,i[suffixpoint:])
        # suffixpoint = checkedVal
    print(suffixpoint)
