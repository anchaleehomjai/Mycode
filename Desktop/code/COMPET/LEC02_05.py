def sum_gcd(n):
    G = 0
    for i in range(1,n,1):
        for j in range(i+1,n+1,1):
            count = ggcd(i,j)
            G += count
    print(G)

                    
def ggcd(x,y):
    if y == 0:
        return x
    else:
        return ggcd(y,x%y)
   


def main():
   n = int(input())
   sum_gcd(n)


if __name__ == '__main__':
    main()

