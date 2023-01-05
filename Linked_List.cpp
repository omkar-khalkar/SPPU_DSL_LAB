/*
Department of Computer Engineering has student's club named 'Pinnacle Club'. Students
of second, third and final year of department can be granted membership on request.
Similarly one may cancel the membership of club. First node is reserved for president of
club and last node is reserved for secretary of club. Write C++ program to maintain club
member‘s information using singly linked list. Store student PRN and Name. Write
functions to:
a) Add and delete the members as well as president or even secretary.
b) Compute total number of members of club
c) Display members
d) Two linked lists exists for two divisions. Concatenate two lists

*/

#include <iostream>
#include <cstring>
using namespace std;

struct node
{

    string prn;
    string name;
    node *next;
};

class Pinnacle
{

    node *head;

public:
    Pinnacle()
    {
        head = NULL;
    }
    void create();
    void insertatStart();
    void insertatEnd();
    void insert();
    void deleteAtbeg();
    void deleteAt();
    void rev();
    void concatenate(Pinnacle A, Pinnacle B);
    void display(node *t);
    void list();
};

void Pinnacle::create()
{

    struct node *t = head;
    if (t == NULL)
    {
        t = new struct node;
        cout << "Enter the PRN No.:";
        cin >> t->prn;
        cout << "ENter the Name :";
        cin >> t->name;
        t->next = NULL;
        head = t;
    }
}

void Pinnacle::insertatStart()
{

    struct node *temp = head;
    if (temp == NULL)
    {
        create();
    }
    else
    {

        temp = new struct node;
        cout << "Enter the PRN No.:";
        cin >> temp->prn;
        cout << "ENter the Name :";
        cin >> temp->name;
        temp->next = head;
        head = temp;
    }
}
void Pinnacle::concatenate(Pinnacle A, Pinnacle B)
{
    struct node *temp = A.head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = B.head;
    display(A.head);
}

void Pinnacle::insertatEnd()
{

    struct node *temp = head;
    if (temp == NULL)
    {
        create();
    }
    else
    {

        while (temp->next != NULL)
            temp = temp->next;

        node *n = new struct node;

        cout << "Enter the PRN No.:";
        cin >> n->prn;
        cout << "Enter the Name :";
        cin >> n->name;
        temp->next = n;
        n->next = NULL;
    }
}
void Pinnacle::display(struct node *t)
{

    {
        cout << "\nLINKED LIST \n";
        while (t != NULL)
        {
            cout << "PRN :" << t->prn << " NAME: " << t->name << endl;
            t = t->next;
        }
    }
}

void Pinnacle::insert()
{
    int count = 0;
    int i;
    cout << "\nEnter The Position You want To Insert: ";
    cin >> i;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    if (i > count || i < 0)
    {
        cout << "\n Enter a valid position.\n";
    }

    else
    {
        struct node *temp = head;
        for (int j = 1; j < i - 1; j++)
        {
            temp = temp->next;
        }
        struct node *n = new node;
        cout << "Enter the PRN No.:";
        cin >> n->prn;
        cout << "ENter the Name :";
        cin >> n->name;
        n->next = temp->next;
        temp->next = n;
    }
}

void Pinnacle::deleteAtbeg()
{
    struct node *temp = head;
    head = temp->next;
    delete temp;
}

void Pinnacle::deleteAt()
{
    struct node *temp;
    struct node *n;
    struct node *p;
    temp = head;
    int i, pos, count;
    count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    cout << "\nEnter the Index you want to delete : ";
    cin >> i;

    pos = i - 1;

    if (i == 1)
    {
        deleteAtbeg();
    }

    else if (pos > count || i <= 0)
    {
        cout << "Position is Not Correct";
    }

    else
    {
        temp = head;
        while (pos--)
        {
            p = temp;
            temp = temp->next;
            n = temp->next;
        }

        p->next = n;
        delete temp;

        cout << "Entered position is deleted";
    }
}

void Pinnacle::rev()
{

    struct node *current = head;
    struct node *nex = NULL;
    struct node *pre = NULL;
    while (current != NULL)
    {
        nex = current->next;
        current->next = pre;
        pre = current;
        current = nex;
    }
    head = pre;
}

void Pinnacle::list()
{
    int ch;
    do
    {
        cout << "\n1->Insert\n";
        cout << "2->Delete\n";
        cout << "3->Reverse\n";
        cout << "4->Display\n";
        cout << "5.EXIT\n";
        cout << "Enter Your Choice\n";
        cin >> ch;
        switch (ch)
        {

        case 1:
            do
            {
                cout << "\n1->Insert President\n";
                cout << "2->Insert Secretary\n";
                cout << "3->Insert Member\n";
                cout << "0->Previous\n";

                cout << "\nEnter Your Choice\n";
                cin >> ch;
                switch (ch)
                {
                case 1:
                    insertatStart();
                    break;

                case 2:
                    insertatEnd();
                    break;

                case 3:
                    insert();
                    break;
                }

            } while (ch != 0);
            continue;

        case 2:
            deleteAt();
            break;

        case 3:
            rev();
            break;

        case 4:
            display(head);
            break;

        case 5:
            break;
        }
    } while (ch != 5);
}

int main()
{
    Pinnacle list, A, B;
    int ch;

    do
    {
        cout << "\n1.LIST 1\n";
        cout << "2.LIST 2\n";
        cout << "3.Concatenate\n";
        cout << "\n Enter Choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            A.list();
            break;

        case 2:
            B.list();
            break;

        case 3:
            list.concatenate(A, B);
        }
    } while (ch != 0);

    return 0;
}
