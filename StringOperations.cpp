
/*

Write a Python program to compute following operations on String:
a) To display word with the longest length
b) To determines the frequency of occurrence of particular character in the string
c) To check whether given string is palindrome or not
d) To display index of first appearance of the substring
e) To count the occurrences of each word in a given string
*/
def longest_word():

    str = input("Enter the string :")
    word1 = ""
    word2 = ""

    for i in str:
        if i != " ":
            word1 += i
            if (len(word1) > len(word2)):
                word2 = word1
        else:
            word1 = ""

    return word2


def occurence_first():
    str = input("Enter the string: ")
    sub = input("Enter the substring: ")
    l1 = len(str)
    l2 = len(sub)
    flag = 0
    lst = []
    for i in range(l1 - l2 + 1):
        co = 0
        for j in range(l2):
            if (str[i + j] == sub[j]):
                co = co+1
                if co == len(sub):
                    flag = 1
                    lst.append(i)
    if flag > 0:
        print("Substring is occur at : ")
        for i in lst:
            print(i, end=" ")
    else:
        print("Substring is not found ")


def occurence_eachword():
    str = input("enter the string: ")
    lst = []
    word = ""
    for i in str:
        if i != " ":
            word += i

        else:
            lst.append(word)
            word = ""
    lst.append(word)
    print(lst)
    lst1 = []
    for i in lst:
        if i not in lst1:
            lst1.append(i)

    for i in range(0, len(lst1)):
        sub = lst1[i]
        l1 = len(str)
        l2 = len(sub)
        flag = 0

        for i in range(l1 - l2 + 1):
            co = 0
            for j in range(l2):
                if (str[i + j] == sub[j]):
                    co = co+1
                    if co == len(sub):
                        flag = flag+1
        if flag > 0:
            print("The \"{}\" Occurs in String for %d times.".format(sub) % flag)
        else:
            print("Word Is Not Found in Given String ")


def remove_spaces(str):
    a = ""
    for i in str:
        if i != " ":
            a += i
    return a


def character_occurence():
    count = 0
    str = input("Enter the String : ")
    C = input("Enter The Character : ")
    for i in str:
        if i == C:
            count = count + 1
    return count


def check_palindrome():
    str = input("Enter the String: ")
    str1 = remove_spaces(str)
    b = len(str1)-1
    new = ""
    while b >= 0:
        new += str1[b]
        b -= 1
    if (new == str1):
        print("This is Palindrome ")
    else:
        print("This is Not Palindrome ")


while (1):
    print("\n*************************************************************************\n")
    
    print(" 1. To display word with the longest length")
    print(" 2. To determines the frequency of occurrence of particular character in the string")
    print(" 3. To check whether given string is palindrome or not")
    print(" 4. To display index of first appearance of the substring")
    print(" 5. To count the occurrences of each word in a given string.")
    print(" 6. EXIT \n ")

    print("\n*************************************************************************\n")

    ch = int(input("Enter Your Choice : "))
    if ch == 1:
        print("Word with the longest length : ", longest_word())

    elif ch == 2:
        print("Frequency of occurrence of particular character in the string : ",
              character_occurence())

    elif ch == 3:
        check_palindrome()

    elif ch == 4:
        occurence_first()

    elif ch == 5:
        occurence_eachword()

    else:
        break
