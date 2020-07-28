f= open('backforth.in','r+')
cont = f.readlines()
f.close()
cont= [i.rstrip('\n').split() for i in cont]
for i in cont:
    for j in range(10):
        i[j] = int(i[j])
#do we need 10 nested for loops?
#no, we need recursion
bk1 = cont[0]
bk2 = cont[1]
ret = []

def move(buckInd,b1 = list(bk1),b2 = list(bk2),barn1=0,barn2=0,day=0):
    print(b1,b2)
    if day == 4:
        global ret
        ret.append(b1)
    else:
        #does the barns
        print b1,b2
        barn1,barn2 = barn1 -b1[buckInd],barn2 +b1[buckInd]
        #does the buckets
        b2.append(b1.pop(buckInd))
        for i in range(len(b2)):
            move(i,b2,b1,barn1,barn2,day+1)

for i in range(10):
    move(i)
