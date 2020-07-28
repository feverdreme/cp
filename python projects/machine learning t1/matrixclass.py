class matrix():
    def __init__(self,dim):
        self.dim = dim
        self.m = []
    def init2(self,dim = 0):
        tempdim = list(self.m)
        if dim == len(self.dim):
            return
        elif not dim:
            for x in range(0,self.dim[0]):
                self.m.append(1)
        else:
            for x in range(0,self.dim[dim] - 1):
                tempdim.append(self.m)
                print(self.m)
        self.m = tempdim
        self.init2(dim+1)
p = matrix([2,2,3])
p.init2()
