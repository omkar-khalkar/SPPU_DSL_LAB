/*
In second year computer engineering class, group A student’s play cricket, group B
students play badminton and group C students play football.
Write a Python program using functions to compute following: -
a) List of students who play both cricket and badminton
b) List of students who play either cricket or badminton but not both
c) Number of students who play neither cricket nor badminton
d) Number of students who play cricket and football but not badminton.
(Note- While realizing the group, duplicate entries should be avoided, Do not use SET
built-in functions) 

*/

cricket = []
print('\n***********************************************')
n = int(input("Enter the No. of Students Who Play Cricket : "))
for i in range(1, n+1):
    ele = int(input("Enter Roll No. of %d Student :\n" % i))
    cricket.append(ele)
print("The Student Who Play Cricket : ", cricket)
print('\n***********************************************')

badminton = []
# print('\n***********************************************\n')
n = int(input("Enter the No. of Students Who Play Badminton : "))
for i in range(1, n+1):
    ele = int(input("Enter Roll No. of %d Student:\n" % i))
    badminton.append(ele)
print("The Student Who Play badminton : ", badminton)
print('\n***********************************************')

football = []
# print('\n***********************************************\n')
n = int(input("Enter the No. of Students Who Play Football :  "))
for i in range(1, n+1):
    ele = int(input("Enter Roll No. of %d Student : \n" % i))
    football.append(ele)
print("The Student Who Play badminton : ", football)
print('\n***********************************************\n')


def intersection(a, b):
    inter = []
    for i in a:
        if i in b:
            inter.append(i)
    return inter


def union(a, b):
    un = a
    for i in b:
        if i not in un:
            un.append(i)
    return un


def diff(a, b):
    d = []
    for i in a:
        if i not in b:
            d.append(i)
    return d


def symm_diff(a, b):
    d1 = diff(a, b)
    d2 = diff(b, a)
    x = union(d1, d2)
    return x


while (1):
    print('\n____________________________________________________________________\n')

    print("1.List of student who play Cricket and Badminton both")
    print("2.List of Student who play either Cricket and Football")
    print("3.Number of students who play neither cricket nor Badminton")
    print("4.Number of students who play cricket and football but not Badminton")
    print("5.EXIT")

    print('\n____________________________________________________________________')
    ch = int(input("Enter your choice(1/2/3/4/5) : \n"))
    if ch == 1:
        print("List of Student Who Play Cricket and Badminton Both :",
              intersection(cricket, badminton))
    elif ch == 2:
        print("List of Student Who play Either Cricket or Badminton :",
              symm_diff(cricket, badminton))
    elif ch == 3:
        print("Number of Students Who play Neither Cricket nor Badminton: ",
              diff(football, union(cricket, badminton)))
    elif ch == 4:
        print("Number of Students Who play Cricket and Football But Not Badminton :", diff(
            union(cricket, football), badminton))
    else:
        break
