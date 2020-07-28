"""
PROG: ride
LANG: PYTHON3
"""

a = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
apl = {a[i] : i+1 for i in range(26)}
f= open('ride.in','r')
cont = f.readlines()
f.close()
for i in range(len(cont)):
    cont[i] = cont[i].rstrip('\n')

sums = [1,1]
for i in range(2):
    for j in cont[i]:
        sums[i] = sums[i] * apl[j]
f= open('ride.out','w+')
if sums[0] % 47 == sums[1] % 47:
    f.write('GO\n')
else:
    f.write('STAY\n')
