import sys
# from math import floor as fl
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
num = int(cont.pop(0)[0])

for i in cont:
    n,r = [int(j) for j in i]
    count = 0
    # for j in range(1,r+1):
    #     if n >= j + 1:
    #         count += j
    #     elif n == j:
    #         count += 1
    if n <= r:
        #then theres n + r-n
        print((n+1)*n//2 + (r-n))
    print(count)
