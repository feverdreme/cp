f= open('word.in','r+')
cont= f.readlines()
f.close()

cont = [i.rstrip('\n') for i in cont]
cont[0] = cont[0].split()
K = int(cont[0][1])
cont.pop(0)
cont = cont[0].split()
f= open('word.out','w+')
cont = [i+' ' for i in cont]


count = 0
ret = ''

for i in cont:
    if len(i) + count >= K:
        ret += i.rstrip() + '\n'
        count = 0
    else:
        ret += i
        count += len(ret)
# ret.rstrip()
f.write(ret.rstrip())
print(repr(ret))
