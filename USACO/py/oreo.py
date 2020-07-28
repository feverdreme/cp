#first do teh normal checks
x = input()

isprime = True
for d in range(2,x//2):
    if isprime and x%d == 0:
        isprime = False
    else:
        pass
print(isprime)
