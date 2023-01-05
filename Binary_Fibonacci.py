"""

Write a python program to store roll numbers of student array who attended training
program in sorted order. Write function for searching whether particular student
attended training program or not, using Binary search and Fibonacci search

"""

def binary_search(A, s, l, x):
    mid = int((s+l)/2)
    if (l >= s):
        if x == A[mid]:
            return mid
        if x > A[mid]:
            return binary_search(A, mid+1, l, x)
        else:
            return binary_search(A, s, mid-1, x)
    return -1


def bubble_sort(a):
    for k in range(1, len(a)):
        for j in range(len(a)-k):
            if a[j] > a[j+1]:
                temp = a[j]
                a[j] = a[j+1]
                a[j+1] = temp
    return a


def ternary_search(lst, s, l, x):
    mid1 = int(s + (l-s)/3)
    mid2 = int(l - (l-s)/3)
    if l >= s:
        if x == lst[mid1]:
            return mid1
        elif x == lst[mid2]:
            return mid2
        elif x < lst[mid1]:
            return ternary_search(lst, s, mid1-1, x)
        elif x > lst[mid2]:
            return ternary_search(lst, mid2+1, l, x)
        else:
            return ternary_search(lst, mid1+1, mid2-1, x)
    return -1


def FibonacciSearch(arr, x, n):

    b = 0
    a = 1
    f = b + a

    while (f < n):
        b = a
        a = f
        f = b + a

    offset = -1

    while (f > 1):

        i = min(offset+b, n-1)

        if (arr[i] < x):
            f = a
            a = b
            b = f - a
            offset = i

        elif (arr[i] > x):
            f = b
            a = a - b
            b = f - a

        else:
            return i

    if (a and arr[n-1] == x):
        return n-1
    return -1


while (1):
    print("**********************************************************************")
    print("\t\t\t1-->Accept List")
    print("\t\t\t2-->Binary Search")
    print("\t\t\t3-->Ternary Search")
    print("\t\t\t4-->Fibbonacci Search")
    print("\t\t\t5-->Exit")

    print("**********************************************************************\n")
    ch = int(input("Enter your Choice : "))
    if ch == 1:
        print("\n------------------------------------------>Accept List<---------------------------------------\n")
        lst = []
        n = int(input("Enter The Total Number Of Student : "))
        for i in range(0, n):
            ele = int(input("Enter The Roll No : "))
            lst.append(ele)
        print("\nLIST = ", lst)
        print("SORTED LIST = ",bubble_sort(lst))
        print("\n------------------------------------------------------------------------------------------------\n")

    elif ch == 2:
        print("\n----------------------------------------->Binary Search<-----------------------------------------\n")
        lst = bubble_sort(lst)
        key = int(input("Enter the Roll No. To be Searched:"))
        result = binary_search(lst, 0, len(lst), key)

        if (result >= 0):
            print("The Roll Number Is Found At ", result)
        else:
            print("Roll Number  Is Not Found")

        print("\n-------------------------------------------------------------------------------------------------\n")
    elif ch == 3:

        print("\n----------------------------------------->Ternary Search<-----------------------------------------\n")
        lst = bubble_sort(lst)
        key = int(input("Enter the Roll No. To be Searched:"))
        result = ternary_search(lst, 0, len(lst)-1, key)

        if (result >= 0):
            print("The Roll Number Is Found At ", result)
        else:
            print("Roll Number  Is Not Found")

        print("\n-------------------------------------------------------------------------------------------------\n")
    elif ch == 4:

        print("\n----------------------------------------->Fibonacci Search<-----------------------------------------\n")
        lst = bubble_sort(lst)
        key = int(input("Enter the Roll No. To be Searched:"))
        result = FibonacciSearch(lst, key, len(lst)-1)

        if (result >= 0):
            print("The Roll Number Is Found At ", result)
        else:
            print("Roll Number  Is Not Found")

        print("\n-------------------------------------------------------------------------------------------------\n")
    else:
        break
