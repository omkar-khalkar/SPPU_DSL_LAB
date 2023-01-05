/*
In any language program mostly syntax error occurs due to unbalancing delimiter such as
(),{},[]. Write C++ program using stack to check whether given expression is well
parenthesized or not.

*/
#include <iostream>
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
    char stack_top();
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
    if (top == size-1)
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

char STACK::stack_top()
{
    char x;
    x = stk[top];
    return x;
}

int main()
{
    STACK s;
    char exp[20], c;
    int i = 0;

    cout << "\nEnter the Expression:  ";
    cin >> exp;

    if ((exp[0] == ')') || (exp[0] == ']') || (exp[0] == '}'))
    {
        cout << "\n Invalid Expresion.....\n";
    }
    
    else
    {
        while (exp[i] != '\0')

        {
            c = exp[i];

            if (c == '(' || c == '{' || c == '[')
                s.push(c);

            else if (c == ')')
            {

                if (s.stack_top() == '(')
                {
                    s.pop();
                }

                else
                {
                    break;
                }
            }

            else if (c == '}')
            {

                if (s.stack_top() == '{')
                {
                    s.pop();
                }
                else
                {
                    break;
                }
            }
            else if (c == ']')
            {

                if (s.stack_top() == '[')
                {
                    s.pop();
                }
                else
                {
                    break;
                }
            }

            i++;
        }
    }

    if (s.isempty())
    {
        cout << "\nExpression is Paranthesized\n";
    }

    else
    {
        cout << "\nExpression is not Parenthesized....\n";
    }
    return 0;
}
