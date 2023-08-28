#!/usr/bin/env python3
# อัญชลี หอมใจ
# 640510690
# Lab 04
# Problem 3
# 204111 Sec 001

def calculate_p2p_evolve_exp(p, c):
    if p == 0:
        return 0
    evo =((p+c)-2)//11  #จำนวนรอบที่ใช้แปลงร่าง
    if p <= evo: #ถ้านก <=  evo  exp = เอานก*จำนวนรอบเลย 
        exp = p*500
    else:
        evo = ((p+c)-2)//11
        exp = evo*500
    return exp
     


def main():
    # receive input from user
    p = int(input())
    c = int(input())
    # print result from function
    print(calculate_p2p_evolve_exp(p, c))

if __name__ == '__main__':
    main() 

