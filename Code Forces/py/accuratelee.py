import sys
cont = sys.stdin.readlines()
cont = [i.strip('\n') for i in cont]
numTests = int(cont.pop(0)[0])
cont  =[i for ind,i in enumerate(cont) if ind%2 == 1]

# def recur(string):
#     if string.count('10') == 0:
#         return string
#     else:
#         t1 = recur(string.replace('10','1',1))
#         t2 = recur(string.replace('10','0',1))
#         if len(t1) != len(t2):
#             return min(t1,t2,key=len)
#         else:
#             return min(t1,t2)

for i in cont:
    #scan through, find teh first one, check if there is a one to the left and continue
    # while i.count('10') != 0:
    #     #this means that some exists
    #     ind = i.index('10')
    #     if ind+2 < len(i) and i[ind+2] == '1':
    #         i = i.replace('10','0',1)
    #     elif ind+2 < len(i) and i[ind+2] == '0':
    #         i = i.replace('10','1',1)
    #     else:
    #         i = i.replace('10','0',1)
    # print(i)
    for ind,i in enumerate(cont):
        if i + cont[ind+1] == '10':
            #then this is a match
            if cont[ind+2] == '1':
                cont = cont[:ind] + '0' + cont[ind+1:]
            else:
                cont = cont[:ind] + '1' + cont[ind+1:]
        print(i)
