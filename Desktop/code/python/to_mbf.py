
def doulove(result):
    posed = "y" or "Y"
    if(result == posed):
        ans = print("Me too! <3")
        return ans
    else:
        print("try again pls ;-;")
        print('you want try again?(Y/N)')
        result2 = str(input("answer: "))
        ans = tryagain(result2)
        return ans


def tryagain(result2):
    posed2 = "y" or "Y"
    if(result2 == posed2):
        ans = doulove(posed2)
        return ans
    else:
        ans = print(' T T')
        return ans
        


def main():
    push = int(input('push 1 to start! pls: '))
    if(push == 1):
        print("Do you love me? (Y/N)")
        result = str(input("answer: "))
        doulove(result)

if __name__=='__main__':
    main()
    
