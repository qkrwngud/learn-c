from random import *


def dd(lst1):
    for i in range(len(lst1)-1):
        for j in range(len(lst1) -1):
            if lst1[j] > lst1[j +1]:
                tmp = lst1[j + 1]
                lst1[j + 1] = lst1[j]
                lst1[j] = tmp
    for i in range(len(lst1)):
        print(lst1[i])


lst1 = []

for i in range(5):
    a = randint(1, 46)
    lst1.append(a)

dd(lst1)
