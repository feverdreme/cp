import sys
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
n = int(cont.pop(0)[0])
cont=cont[0]
cont = [bin(int(i))[2:] for i in cont]

t = len(max(cont,key=len))

for i in range(len(cont)):
    cont[i] = '0'*(t - len(cont[i])) + cont[i]

def andN(x,y):
    x = list(x)
    for i in range(len(x)):
        x[i] = str(int(x[i]) or int(y[i]))
    ret = ''
    for i in x:
        ret += i
    return ret

#get the one with most ones
max1 = -1
most1 = ''

for i in cont:
    if i.count('1') >= max1:
        max1 = i.count('1')
        most1 = i
