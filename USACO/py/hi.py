f= open("socdist1.in","r+")
contents = f.readlines()
f.close()
N = int(contents[0].rstrip("\n"))
stri = contents[1].rstrip("\n")
#output global
maxout = 0
out = 0
help = []
#find all distances
def findD(st):
    global out
    global help
    help = []
    #if the min and max D's are consecutive, then that means it is correct
    #finds all location of 1
    ltion = []
    for y in range(0,len(st)):
        if st[y] == "1":
            ltion.append(y)
    #find all D
    first = ltion[0]
    tD = 0
    for x in range(1,len(ltion)):
        tD = ltion[x] - first
        first = ltion[x]
        help.append(tD)
    #check that even
    if st[N - 3] == "0":
        last1 = ltion.pop()
        leng = N - 2 - last1
        end = leng
        help.append(end)
    #check
    print(help)
    if max(help) - min(help) <= 1:
        out = max(help)
        return True
    else:
        return False
#brute for every 0
#make list for every 0 position
pos0 = []
for z in range(0,len(stri)):
    if stri[z] == "0":
        pos0.append(z)
#do the brute
for pos1 in pos0:
    for pos2 in pos0:
        if pos1 != pos2:
            tempstri = list(stri)
            tempstri[pos1] = '1'
            tempstri[pos2] = '1'
            if findD(tempstri):
                if maxout < out:
                    maxout = out
            print(pos1,pos2)
f= open("socdist1.out","w+")
f.write(str(int(maxout)))
f.close()
