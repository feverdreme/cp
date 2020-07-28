from random import randint
ret = ''
def memeify(str):
    for i in str:
        if randint(0,1):
            i = i.lower()
        else:
            i = i.upper()
    print(str)
memeify('finenvornviernvoernvoiernv')
