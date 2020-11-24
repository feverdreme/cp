import sys
from math import floor as fl
from math import ceil as ce
from math import sqrt
cont = sys.stdin.readlines()
cont = [i.strip('\n').split() for i in cont]
num = int(cont.pop(0)[0])
def invert(string):
    ret = ''
    for i in string:
        if i == '1':
            ret += '0'
        else:
            ret += '1'
    return ret

alpha = 'qwertyuioplkjhgfdszxcvnm'

for i in range(num):
    l = int(cont.pop(0)[0])
    nums = [int(j) for j in cont.pop(0)]
    maxlen = max(nums)
    ret = []
    for ind,i in enumerate(nums):
        if ind == len(nums)-1:
            break
        if i == 0:
            ret.append(0)
            continue
        next = nums[ind+1]
        if next >= i:
            ret.append("a" * next)
        else:
            ret.append("a" * i)
    ret.append("a" * nums[-1])
    ret = ["a"*nums[0]] + ret
    print(ret)
    curind = 0
    # while '' in ret:
    #     #there are zeros in it
    #     ind = ret.index('')
    #     ret[ind] = alpha[curind]
    #     curind = (curind + 1)%24
    # r = ''
    # for i in ret:
    #     print(i)
