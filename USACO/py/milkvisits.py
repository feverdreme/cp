f= open('milkvisits.in','r+')
cont = f.readlines()
f.close()
cont = [i.strip('\n').split() for i in cont]
N,M = cont.pop(0)
N,M = int(N),int(M)
cows = cont.pop(0)[0]
connections = cont[:N-1]
visits = cont[N-1:]

class node:
    def __init__(self,num,milk):
        self.num = num
        self.milk = milk
        self.edges = []
    def add(self,node):
        self.edges.append(node)
        node.edges.append(self)
    # def __repr__(self):
    #     return self.num

nodes = [node(str(ind+1),i) for ind,i in enumerate(cows)]

for i in connections:
    i[0] = int(i[0])-1
    i[1] = int(i[1])-1

for i in connections:
    nodes[i[0]].add(nodes[i[1]])

groups = []

def dfs(node):
    global nodes,groups
    stack = [node]
    milk = node.milk
    tgroup = []
    while True:
        if len(stack) == 0:
            groups.append(tgroup)
            break
        temp = stack.pop()
        if temp.milk != milk:
            groups.append(tgroup)
            break
        for i in temp.edges:
            if i not in nodes and i not in tgroup:
                tgroup.append(i)
                stack.append(i)
                nodes.remove(i)

while len(nodes) != 0:
    dfs(nodes[0])

# f=open('milkvisits.out','w+')
# f.write(ret)
# f.close()
