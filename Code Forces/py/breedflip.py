f= open('breedflip.in','r+')
cont = f.readlines()
cont = [i.rstrip('\n') for i in cont]
N = int(cont.pop(0))

match = ''
for i in range(N):
    if cont[0][i] == cont[1][i]:
        match += '0'
    else:
        match += '1'
match = match.split('0')
match = [i for i in match if i != '']

f = open('breedflip.out','w+')
f.write(str(len(match)))
f.close()
