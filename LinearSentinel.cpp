/*
Write a pythonprogram to store roll numbers of student in array who attended
training program in random order. Write function for searching whether particular
student attended training program or not, using Linear search and Sentinel search.
*/

def linear_search(A, n, key):
    for i in range(n):
        if A[i] == key:
            return i
    return -1


def sentinal_search(A, n, key):
    last = A[n-1]
    A[n-1] = key
    i = 0
    while (A[i] != key):
        i = i+1
    A[n-1] = last
    if (i < n-1 or last == key):
        print(f"The Key Is Present At Index {i}")
    else:
        print("The Key Is Not Found ")


while (1):
    print("**********************************************************************")
    print("\t\t\t1-->Accept List")
    print("\t\t\t2-->Linear Search")
    print("\t\t\t3-->Sentinal Search")
    print("\t\t\t4-->Exit")

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
        print("\n------------------------------------------------------------------------------------------------\n")
    elif ch == 2:
        print("\n----------------------------------------->Linear Search<--------------------------------------\n")
        key = int(input("Enter the Roll No.:"))
        result = linear_search(lst, len(lst), key)

        if (result >= 0):
            print(f"The Roll Number Is Found At {result}")
        else:
            print("Roll Number  Is Not Found")

        print("\n------------------------------------------------------------------------------------------------\n")

    elif ch == 3:
        print("\n----------------------------------------->Sentinal Search<--------------------------------------\n")

        key = int(input("Enter the Roll No.:"))
        sentinal_search(lst, len(lst), key)

        print("\n-------------------------------------------------------------------------------------------------\n")

    else:
        break
