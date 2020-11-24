# import builtins
#
# class mystr(object):
#     """docstring for mystr."""
#
#     def __init__(self, arg):
#         super(mystr, self).__init__()
#         self.arg = arg
#     def condense(self):
#         return self.arg
#
#
# builtins.str = mystr
#
# x = mystr('4554')
# print(x.condense())
def condense(str_):
    if len(str_) == 0:
        return str_
    ret =''
    curr = str_[-1]
    ret += curr
    while len(str_):
        str_ = str_.rstrip(curr)

        if len(str_):
            curr = str_[-1]
            ret += curr
    return ret[::-1]


cin = input("? ")
print(condense(cin))
