char = 'abcdefghijklmnopqrstuvwxyz'
spec = '!@#$%^&*()?'

all = []
#create this list
for x in char:
    all.append(x)
    all.append(x.upper())
for x in spec:
    all.append(x)
all.append('')

import datetime
times = []
def gett():
    global datetime
    global times
    times.append(str(datetime.datetime.minute)+'min '+str(datetime.datetime.second)+'sec '+str(datetime.datetime.microsecond)+'us' )
gett()
password = 'L0llip0p!'
isCracked = False
def foo(dep = 1, rstr = ''):
    global isCracked
    if not isCracked:
        if not (dep % 9):
            print(rstr)
            if rstr == password:
                print('password: '+rstr)
                isCracked = True
                gett()
            return
        for chars in all:
            foo(dep+1,rstr + chars)
    else:
        return
foo(1,'')
print(times)
