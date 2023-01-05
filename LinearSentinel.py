
"""
Write a python program to store first year percentage of students in array. Write function
for sorting array of floating point numbers in ascending order using
a) Selection Sort
b) Bubble sort and display top five scores.

"""

def bubblesort(lst):
    for i in range(1, len(lst)):
        for j in range(len(lst)-i):
            if lst[j] > lst[j+1]:
                lst[j+1], lst[j] = lst[j], lst[j+1]
    return lst;


def selectionsort(lst):
    for i in range(len(lst)):
        min = i
        for j in range(i+1, len(lst)):
            if lst[min] > lst[j]:
                min = j
        lst[i], lst[min] = lst[min], lst[i]
    return lst;


while (1):
    print("**********************************************************************")
    print("\t\t\t1-->Accept Percentage")
    print("\t\t\t2-->Sort using Selection Sort")
    print("\t\t\t3-->Sort using Bubble Sort")
    print("\t\t\t4-->Display")
    print("\t\t\t5-->Exit")

    print("**********************************************************************\n")
    ch = int(input("Enter your Choice : "))
    if ch == 1:
        n=int(input("Enter The No. Of Students: "))
        lst =[]
        for i in range(0,n):
            ele=int(input("Enter The Percentage : "))
            lst.append(ele)
        print("LIST =",lst)
    elif ch == 2:
        lst1 = selectionsort(lst);
        print("SORTED LIST = ",lst1)
    elif ch == 3:
        lst2 = bubblesort(lst);
        print("SORTED LIST = ",lst2)
    elif ch == 3:
        for i in range(1,6):
            print(f"TOP {i} = ",lst1[-i])

        


    else:
        break
