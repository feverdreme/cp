f= open('mixmilk.in','r+')
cont = f.readlines()
f.close()
cont = [i.rstrip('\n').split() for i in cont]
for i in cont:
    i[0] = int(i[0])
    i[1] = int(i[1])
c1 = cont[0][0]
m1 = cont[0][1]
c2 = cont[1][0]
m2 = cont[1][1]
c3 = cont[2][0]
m3 = cont[2][1]
"""
    first we take the first bucket and find if it cna fit
    if it can:
        m2 = m1 + m2
        m1 = 0
    if it cant:
        m1,m2 = m1+m2 - c2,c2
"""
#x=[1,2,3]
#x.append(x.pop(0))
#print x
foo = [m1,m2,m3]
foo2 = [c1,c2,c3]
def pour(b1,b2,bc1,bc2):
    #doo
    if b1+b2 <= bc2:
        b1,b2 = 0,b1+b2
    else:
        b1,b2 = b1+b2-bc2,bc2
    return [b1,b2]
for i in range(100):
    foo[0], foo[1] = pour(foo[0], foo[1], foo2[0], foo2[1])
    foo.append(foo.pop(0))
    foo2.append(foo2.pop(0))
foo.append(foo.pop(0))
foo2.append(foo2.pop(0))
foo.append(foo.pop(0))
foo2.append(foo2.pop(0))
f = open('mixmilk.out','w+')
ret = ''
for i in foo:
    ret += str(i) + '\n'
f.write(ret)
