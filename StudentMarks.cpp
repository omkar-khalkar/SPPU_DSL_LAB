/*

Write a Python program to store marks scored in subject “Fundamental of Data
Structure” by N students in the class. Write functions to compute following:
a) The average score of class
b) Highest score and lowest score of class
c) Count of students who were absent for the test
d) Display mark with highest frequency

*/
global n, marks
n = int(input('Enter the number of students :'))
marks = []
for i in range(1, n+1):
    mark = input('Enter the number of %d student ' % (i))
    if mark == 'AB' or mark == 'ab':
        mark = -1
        marks.append(mark)
    elif int(mark) < 0 and int(mark) > 30:
        print('Wrong input')
        break
    elif int(mark) >= 0 and int(mark) <= 30:
        marks.append(int(mark))


def display():
    for i in range(0, n):
        if marks[i] == -1:
            print('Marks of student %d is :' % (i+1), 'Absent')
        else:
            print('Marks of student %d is :%d' % (i+1), marks[i])


display()


def countting():
    global count
    count = 0
    for i in range(0, n):
        if marks[i] == -1:
            count = count+1
        else:
            count = count
    return count


print('Number of absent students is ', countting())


def avg():
    avg = 0
    sum = 0
    for i in range(0, n):
        if marks[i] != -1:
            sum = sum + marks[i]
        elif marks[i] == -1:
            sum = sum
    avg = (sum/(n-count))
    print('Average of Marks', avg)


avg()


def max():
    max = marks[0]
    for i in range(1, n):
        if max >= marks[i]:
            max = max
        elif marks[i] > max:
            max = marks[i]
    print('Maximum marks are : ', max)


max()


def min():
    min = 30
    for i in range(0, n):
        if marks[i] == -1:
            continue
        elif marks[i] <= min:
            min = marks[i]
    print('Minimum marks are : ', min)


min()


def frequency():
    freq = 0
    for i in range(0, n):
        k = marks[i]
        co = 0
        for j in range(0, n):
            if (k == marks[i] and marks[i] == -1):
                continue
            elif (k == marks[j]):
                co = co + 1
            else:
                co = co
        if (co > freq):
            freq = co
            m = k
        else:
            freq = freq
    if freq == 1:
        print("There is no such highest frequency every student have different marks")
    else:
        print("The highest frequency is %d of marks %d " % (freq, m))


frequency()
