pi = 0
import numpy as np
pi = np.pi

amazing = [22756411.0, 7243591]
a = 242735039.0
b = 77264963

#a = 22000000000000.0
#b = 7000000000000
disp = 0

for x in range(0,40000000):
    if a / b > pi:
        b += 1
    else:
        a += 1
    if x % 1000000 == 0:
        disp = x
    print(a / b, disp)
print(a/b)
print(a,b)
