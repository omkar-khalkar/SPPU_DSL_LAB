/*
A palindrome is a string of character that‘s the same forward and backward. Typically,
punctuation, capitalization, and spaces are ignored. For example, “Poor Dan is in a droop”
is a palindrome, as can be seen by examining the characters “poor danisina droop” and
observing that they are the same forward and backward. One way to check for a
palindrome is to reverse the characters in the string and then compare with them the
original-in a palindrome, the sequence will be identical. Write C++ program with
functionsa) To print original string followed by reversed string using stack
b) To check whether given string is palindrome or not
*/

#include <iostream>
#include <cstring>

using namespace std;
#define size 50

class STACK
{
    int top;
    char stk[size];

public:
    STACK()
    {
        top = -1;
    }
    void push(char);
    char pop();
    int isfull();
    int isempty();
    // void string_palindrome(string);
};

void STACK::push(char x)
{
    top = top + 1;
    stk[top] = x;
}

char STACK::pop()
{
    char s;
    s = stk[top];
    top = top - 1;
    return s;
}

int STACK::isfull()
{
    if (top == size)
        return 1;
    else
        return 0;
}

int STACK::isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

string remove_spaces(string s)
{
     string str = "";
    for (int i = 0; i < s.length(); i++)
    {
       if (s[i]!=' ')
       {
        str+=s[i];
       }
        
    }
    return str;
}
       
    

void string_palindrome(string s1)
{
    STACK st;

    string s = remove_spaces(s1);
    string str = "";
    for (int i = 0; i < s.length(); i++)
    {

        st.push(s[i]);
        str += tolower(s[i]);
    }
    string result;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        result += tolower(st.pop());
    }
    cout << "\nReverse String : " << result<<endl;;
    cout<<"str :"<<str;
    if (result == str)
    {
        cout << "\nThe String is Palindrome\n";
    }
    else
    {
        cout << "\nThe String is NOT Palindrome\n";
    }
}

int main()
{
    
    string_palindrome("eye");
}
