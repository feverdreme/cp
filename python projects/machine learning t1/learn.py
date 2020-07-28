#machine learning
from math import exp
var = {
    'i': 10,
    'j': 10,
    'layerlist': [],
}
#create node
class node:
    def __init__(self,weight,bias,i,j):
        self.weight = weight
        self.bias = bias
        self.i = i
        self.j = j
    def adj(self,wh,bh):
        self.weight += wh
        self.bias += bh
#create layer
h = .5
class layer:
    def __init__(self,i):
        self.i = i
        self.j = 0
        self.nodes = []
    def addnode(self,weight,bias):
        self.nodes.append(node(weight,bias,self.i,self.j))
        self.j += 1
for x in range(0,var['i']):
    var['layerlist'].append(layer(x))
    for y in range(0,var['j']):
        var['layerlist'][x].addnode(h,0)

def hypo(x):
    return x
def sigmoid(x):
    return (exp(x))/(1+exp(x))
def ddxsig(x):
    return sigmoid(x) * (1 - sigmoid(x))
def cost(x,t):
    return (t - x) ** 2

input = [1,2,3,4,5,6,7,8,9,10]
wf = lambda i,j : var['layerlist'][i].nodes[j].weight
bf = lambda i,j : var['layerlist'][i].nodes[j].bias
prevn = lambda i,j : var['layerlist'][i-1].nodes[j]

def evall(inputl = [], id=0,jd=0,sum=0):
    if id:
        sum += wf(id,jd) * sum + bf(id,jd)
    else:
        sum = inputl[jd]
    evall()

#cannot complete this due to not being abel to evaluate sum, do not know how to forward propogate
