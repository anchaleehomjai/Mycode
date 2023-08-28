#!/usr/bin/env python3
# อัญชลี หอมใจ
# 640510690
# Lab 05
# Problem 5
# 204111 Sec 001

def zodiac_find(year):
    if year % 12 == 0:
       zodiac = "Monkey"
    elif year % 12 == 1:
        zodiac = "Rooster"
    elif year % 12 == 2:
        zodiac = "Dog"
    elif year % 12 == 3:
        zodiac = "Pig"
    elif year % 12 == 4:
        zodiac = "Rat"
    elif year % 12 == 5:
        zodiac = "Ox"
    elif year % 12 == 6:
        zodiac = "Tiger"
    elif year % 12 == 7:
        zodiac = "Rabbit"
    elif year % 12 == 8:
        zodiac = "Dragon"
    elif year % 12 == 9:
        zodiac = "Snake"
    elif year % 12 == 10:
        zodiac = "Horse"
    elif year % 12 == 11:
        zodiac = "Goat"
    return zodiac

def element_find(year):
    if year % 10 == 0 or year % 10 == 1:
        element = "Metal"
    elif year % 10 == 2 or year % 10 == 3:
        element = "Water"
    elif year % 10 == 4 or year % 10 == 5:
        element = "Wood"
    elif year % 10 == 6 or year % 10 == 7:
        element = "Fire"
    elif year % 10 == 8 or year % 10 == 9: 
        element = "Earth"
    return element

def yin_yang(year):
    if year%2 != 0:
        powwer = "Yin"
    else:
        powwer = "Yang"
    return powwer

def zodiac_element(year):
    return yin_yang(year)+' '+element_find(year)+" "+zodiac_find(year)



def main():
    year = int(input())
    print(zodiac_element(year))


if __name__ == '__main__':
    main()