f= open('swap.in','r+')

cont = f.readlines()

f.close()

cont = [i.strip('\n').split() for i in cont]

N = int(cont[0][0])
K = int(cont[0][1])
A1 = int(cont[1][0])
A2 = int(cont[1][1])
B1 = int(cont[2][0])
B2 = int(cont[2][1])
#create the array
ar = []
for i in range(N):
    ar.append(i+1)

def swap(arr):
    arr = arr[:A1-1] + arr[A1-1:A2][::-1] + arr[A2:]
    arr = arr[:B1-1] + arr[B1-1:B2][::-1] + arr[B2:]
    return arr
finddupe = []
count = 0
for i in range(K):
    if ar in finddupe:
        break
    else:
        finddupe.append(ar)
        count += 1
        ar = swap(ar)
ret = ''
print finddupe
for i in ar:
    ret += str(i) + '\n'
f = open('swap.out','w+')
f.write(ret)
