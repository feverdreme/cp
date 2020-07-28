import sys
cont = sys.stdin.readlines()
cont = [i.strip('\n') for i in cont]
numTests = int(cont.pop(0)[0])

# for s in cont:
#     result = 0
#     init = -1
#     while True:
#         init += 1
#         cur = init
#         ok = True
#         for i in range(len(s)):
#             result += 1
#             if s[i] == '+':
#                 cur += 1
#             else:
#                 cur -= 1
#             if cur < 0:
#                 ok = False
#                 break
#         print(cur,init,s)
#         if ok:
#             break
#     # print(result)
for s in cont:
    
