import math
n = int(input())

if n == 1:
    print(1)
elif(n == 2):
    print(2)


elif(math.log(n, 2) - int(math.log(n, 2)) == 0):
    print(int(math.log(n, 2)))
else:
    print(int(math.ceil((math.log(n, 2) + 1))))