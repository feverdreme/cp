from random import randint
bx = [0,0,1,1,1]
by = [0,0,0,0,0,0,0,0,1,1]

isxandb = 0
isblue = 0.0

for times in range(0,int(3E6)):
    p = randint(0,1)
    if p:
        pr = randint(0,9)
        if by[pr]:
            isblue += 1
    else:
        pr = randint(0,4)
        if bx[pr]:
            isxandb += 1
            isblue += 1
print(100 * isxandb / isblue)
