import sys
# from math import floor as fl
from math import log
cont = sys.stdin.readlines()
cont = [i.strip('\n') for i in cont]
numTests = int(cont.pop(0)[0])

for i in cont:
    n = int(i)
    if n==1:
        print(0)
        continue
    elif (n%2)%3 == 0 or (n%3)%2 == 0:
        #get the powers of 2
        dupn = n
        num3 = 0
        while dupn % 3 == 0:
            dupn = dupn // 3
            num3 += 1
        num2 = len(bin(dupn)) - 3
        # print(num2,num3)
        # num2 = int(log(2*n // (3**num3) , 2)) - 1
        if 2**num2 * 3**num3 !=n:
            print(-1)
            continue
        if num2 > num3:
            print(-1)
        else:
            print(2*num3 - num2)
    else:
        print(-1)
