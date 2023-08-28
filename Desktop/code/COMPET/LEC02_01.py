import math
n = int(input())
listt = []
listt.append(n)
# if n == 1:
#     print(1,1)

while(n != 1):
    
    if(n % 2 == 0):
        n = int(abs(n**(0.5)))
        # print(n)
        listt.append(n)
    else:
        n = int(abs(n**(3/2)))
        # print(n)
        listt.append(n)
# print(listt)
print(max(listt), len(listt))