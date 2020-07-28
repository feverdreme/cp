f= open("lifeguards.in","r+")
cont = f.readlines()
N = int(cont[0])
del cont[0]
f.close()
newcont = []

#removes the /n
for x in range(0,len(cont)):
    cont[x] = cont[x].rstrip("\n")
    cont[x] = cont[x].split()

#create all numbers

#do rem for every item
maxtime = 0
for rem in range(0,len(cont)):
    temparr = list(cont)
    temparr.pop(rem)
    #find all sum
    sum = 0
    for x in temparr:
        sum +=
