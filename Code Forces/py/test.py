from time import perf_counter

t1 = perf_counter()

for i in range(int(1E7)):
    print (i**2)

t2 = perf_counter()
print (t2-t1)

#37.458505015 for python3
#31.341444116958883 for pypy3
