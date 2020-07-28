import numpy as np
n,m = 3,3

matrix = np.zeros((n,m), dtype='int')

for d in range(3):
    #front fill
    for i in range(d+1):
        matrix[i][d-i] = d
    #back fill
    for i in range(d+1):
        matrix[n-i-1][m-d+i-1] = d
print(matrix)
