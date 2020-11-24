import sys
from math import ceil as ce
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
numTests = int(cont.pop(0)[0])
for i in cont:
    i[0] = int(i[0])
    i[1] = int(i[1])

# for i in cont:
#     a,b = i[0],i[1]
#     if a*b == 0:
#         print(0)
#     else:
#         count = 0
#         m,n = max(a,b),min(a,b)
#         count += m // 2
#         m = m % 2
#         n -= count
#         if m == 1 and n >= 2:
#             count += 1
#         print(count)

def little(a,b,count=0):
    #do the while method
    while a*b>=2:
        m = max(a,b)
        n = min(a,b)
        m -= 2
        n -= 1
        count += 1
        a,b = m,n
    print(count)
# for i in cont:
#     a,b = i[0],i[1]
#     if a <= 100 and b <= 100:
#         little(a,b)
#     else:
#         count = 0
#         #do the 3 method
#         temp = min(a//3 , b//3)
#         count += temp * 2
#         a -= temp*3
#         b -= temp*3
#         little(a,b,count)

for i in cont:
    a,b = i[0],i[1]
    m = max(a,b)
    n = min(a,b)
    count = 0
    t = m-n
    if n - t >= 0:
        m -= t*2
        n -= t
        count += t
        t2 = min(m//3,n//3)
        m -= t2*3
        n -= t2*3
        count += t2*2
        if m*n >= 2:
            count += 1
        print(count)
    else:
        if m - 2*n >= 0:
            print(count + n)
        else:
            count += (m-n)//2
            if m*n >=2:
                count += 1
            print(count)


    # print(count)
