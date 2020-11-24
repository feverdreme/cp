import sys
from functools import reduce
cont = sys.stdin.readlines()
n = int(cont[0].strip('\n'))

#10 letters
count = [1] * 10

while reduce((lambda x,y: x*y),count) < n:
    count[count.index(min(count))] += 1

ret = ''
key = 'codeforces'

for i in range(10):
    ret += key[i] * count[i]
print(ret)
