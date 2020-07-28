#we want the smallest unique substring
f= open('whereami.in','r+')
cont = f.readlines()
f.close()

cont = [i.rstrip('\n') for i in cont]
N = cont[0]
sstr = cont[1]

minlens = 0
#for every size, check that all substrings are unique
strs = {i:[] for i in range(1,len(sstr)+1)}
#for every substring length
for lens in range(len(sstr)):
    for offset in range(len(sstr)-lens+1):
        sub = sstr[lens:lens+offset]
        if len(sub) != 0:
            x = strs[len(sub)]
            x.append(sub)
            strs.update({len(sub) : x})
#now for every lenght, see if there is no duplciates
for lens in range(1,len(sstr)):
    if len(set(strs[lens])) == len(strs[lens]):
        minlens = lens
        break
f=open('whereami.out','w+')
f.write(str(minlens))
