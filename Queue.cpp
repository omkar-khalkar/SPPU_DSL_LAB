/*

Queues are frequently used in computer programming, and a typical example is the
creation of a job queue by an operating system. If the operating system does not use
priorities, then the jobs are processed in the order they enter the system. Write C++
program for simulating job queue. Write functions to add job and delete job from queue.

*/

#include <iostream>
#define size 10
using namespace std;

class queue
{
    int arr[size];
    int front;
    int back;

public:
    queue()
    {
        front = -1;
        back = -1;
    }

    int isempty()
    {
        if ((front > back) || (back == -1))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int isfull()
    {
        if (back == size - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void enqueue(int i)
    {

        if (isempty())
        {
            front = 0;
        }

        back = back + 1;
        arr[back] = i;
    }

    int delqueue()
    {

        int c = arr[front];

        front++;
        return c;
    }

    void display()
    {
        for (int i = front; i <= back; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    queue q;
    int choice, x;
    do
    {
        cout << "\n 1.Insert Job\n 2.Delete Job\n 3.Display\n 4.Exit\n Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (!q.isfull())
            {
                cout << "\n Enter data: \n";
                cin >> x;
                q.enqueue(x);
                cout << endl;
            }
            else
                cout << "Queue is Full\n";
            break;
        case 2:
            if (!q.isempty())
                cout << "\n Deleted Element = " << q.delqueue() << endl;
            else
            {
                cout << "\n Queue is Empty\n\n";
            }
            break;

        case 3:

            if (!q.isempty())
            {
                cout << "\n DISPLAY QUEUE \n";
                q.display();
            }
            else
                cout << "\n Queue is empty\n\n";
            break;
        }
    } while (choice != 4);
    return 0;
}
