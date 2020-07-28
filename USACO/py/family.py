f= open('family.in','r+')
cont = f.readlines()
f.close()
cont = [i.strip('\n').split() for i in cont]
#we want BB is the of AA
n,a,b = cont.pop(0)

#we want to do this honestly
class cow:
    def __init__(self,name):
        self.name = name
        self.children = set()
        self.parents = set()
    def addChild(self,object):
        self.children.add(object)
    def addParent(self,object):
        self.parents.add(object)
    def __str__(self):
        return self.name
    def __repr__(self):
        return self.name
#now set up the classes
#first, we initialize everything
for i in cont:
    for j in i:
        exec(j+'=cow(\'%s\')' % j,globals())

#now initialize everybody
for i in cont:
    exec(i[0] + '.addChild(%s)' % i[1],globals())
    exec(i[1] + '.addParent(%s)' % i[0],globals())

#now do some recursion with that loop starting from AA
found = False

def traverse(node = AA, path = []):
    if not found:
        if node == BB:
            return path
        else:
            #first do the parents
            return traverse(node.parents)

    else:
        return
