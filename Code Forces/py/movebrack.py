import sys
cont = sys.stdin.readlines()
cont = [i.strip('\n') for i in cont]
numTests = int(cont.pop(0)[0])

cont  = [i for ind,i in enumerate(cont) if ind%2 == 1]

def check(string):
    kept = []
    for i in string:
        if kept == []:
            kept.append(i)
        elif kept[-1] == '(' and i == ')':
            kept.pop()
        else:
            kept.append(i)
    if len(kept) == 0:
        return True
    else:
        return False

for string in cont:
    moves = 0
    if check(string):
        print(0)
        continue

    # while True:
    #     if string == '':
    #         break
    #     elif string[0] == ')' and string[-1] == '(':
    #         string = string[1:-1]
    #         moves += 1
    #     elif len(string)>=2 and string[:2] == '()':
    #         string = string[2:]
    #         moves += 1
    #     elif len(string) >= 2 and string[-2:] == '()':
    #         string = string[:-2]
    #         moves += 1
    #     else:
    #         break

    while True:
        if string.count('()') > 0:
            string = string.replace('()','')
        else:
            break
    # print(string)
    if string == '':
        print(moves)
        continue
    ind = string.index(')(')
    moves += ind + 1
    print(moves)
