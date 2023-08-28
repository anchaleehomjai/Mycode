
def round_to_int(x):
    x_10 = abs(x) * 10 #ทำทศนิยมเป็นจำนวนเต็ม
    x_deci = x_10 % 10 # ได้ตัวเลขท้ายที่ที่จะใช้พิจรณาปัด
    if x_deci >=5 and x >= 0: #จำนวนบวก มีทศนิยม
        return int(x) + 1  
    elif x_deci >= 5 and x < 0: #จำนวนลบ  มีทศนิยม
        return int(x) -1
    else:
        return int(x)


def main():
    # receive input from user
    x = float(input())
    # print result from function
    print(round_to_int(x))

if __name__ == '__main__':
    main()
