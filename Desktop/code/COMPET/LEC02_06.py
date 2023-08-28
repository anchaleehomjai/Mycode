n = int(input())
modd = (10**9) + 7
n2 = n**2
if n2 < modd:
    print (n2)
else:
    print(n2 % modd)