import sys
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
numTests = int(cont.pop(0)[0])

for i in cont:
    a,b,n = i
    a,b,n = int(a),int(b),int(n)
    count = 0
    while a+b <= n:
        a,b = min(a,b)+max(a,b) , max(a,b)
        count += 1

    print(count+1)
