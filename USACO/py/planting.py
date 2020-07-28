f= open('planting.in','r+')
cont = f.readlines()
f.close()
cont = [i.strip('\n').split() for i in cont]
N = int(cont.pop(0)[0])

class Node:
    def __init__(self,num):
        self.name = 'N'+num
        self.edges = set()
        self.color = None
    def addEdge(self,obj):
        self.edges.add(obj)
        obj.edges.add(self)
    def __repr__(self):
        return self.name

nodes = {}

for edges in cont:
    #do the first one
    nodes.setdefault(edges[0],Node(edges[0]))
    nodes.setdefault(edges[1],Node(edges[1]))

for edges in cont:
    nodes[edges[0]].addEdge(nodes[edges[1]])

nodes = nodes.values()
maxd = 0
for i in nodes:
    edges = i.edges
    maxd = max(maxd,len(edges))

f = open('planting.out','w+')
f.write('{}'.format(maxd+1))
f.close()
