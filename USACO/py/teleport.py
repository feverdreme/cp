f= open('teleport.in','r+')
cont= f.readlines()
f.close()
cont = cont[0].strip('\n').split()
a,b,x,y = [int(i) for i in cont]
f= open('teleport.out','w+')
"""
    just try everything
    ge thte min
    of
    a - x, y - b
    a - y, x - b
    a - b
"""

f.write(str(min(
    abs(a-x) + abs(y-b),
    abs(a-y) + abs(x-b),
    abs(a-b)
)))
