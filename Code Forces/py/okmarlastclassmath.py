import sys
from math import floor as fl
from math import ceil as ce
from math import sqrt
cont = sys.stdin.readlines()
cont = [i.strip('\n') for i in cont]
num = int(cont.pop(0)[0])

for i in cont:
    n = int(i)

    #if n is even, then the two numbers are n/2 , their lcm is n/2
    if n%2 == 0:
        n = n//2
        print(f'{n} {n}')

    #if n is odd, then it should be n-1, and 1
    else:
        # m = 0
        # for j in range(3,n//2):
        #     if n%j == 0:
        #         m = j
        # if m == 0:
        #     print(f'{n-1} 1')
        # else:
        #     print(f'{m} {n-m}')

        #instead lets get the prime factors of the number
        factors = set([1])
        j = 2
        while j <= int(ce(sqrt(n))):
            if n % j == 0:
                factors.add(j)
                if j*j != n:
                    factors.add(n//j)
            j += 1
        m = max(factors)
        print(f'{m} {n-m}')
