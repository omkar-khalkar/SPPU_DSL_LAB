/*
Queues are frequently used in computer programming, and a typical example is the
creation of a job queue by an operating system. If the operating system does not use
priorities, then the jobs are processed in the order they enter the system. Write C++
program for simulating job queue. Write functions to add job and delete job from queue.

*/

#include <iostream>
#define max 10
using namespace std;

class deq
{
    int rear = -1;
    int front = -1;
    int data[max];

public:
    int isfull()
    {
        if (((rear + 1) % max) == front)
        {
            return 1;
        }
        return 0;
    }
  
    int isempty()
    {
        if (rear == -1)
        {
            return 1;
        }
        return 0;
    }
  
    void initialize()
    {
        rear = -1;
        front = -1;
    }
  
    void enqueR(int x)
    {
        if (isfull())
        {
            cout << "queue is full....\n";
        }
        else
        {
            if (isempty())
            {
                front = rear = 0;
                data[rear] = x;
            }
            else
            {

                rear = (rear + 1) % max; // data modification in clock_wise direction
                data[rear] = x;
            }
        }
    }
  
    void enquef(int x);
    int dequeatfront();
    int dequer();

    void display()
    {
        cout<<"DEQUE :";
        for (int i = front; i != rear; i=(i+1)%max)
        {
            cout<<data[i]<<" ";
            
        }
        cout<<data[rear]<<endl;
        
        
    }
};

void deq::enquef(int x)
{
    if (isfull())
    {
        cout << "queue is full....\n";
    }
    else
    {
        if (isempty())
        {
            front = rear = 0;
            data[front] = x;
        }
        else
        {
            front = (front - 1 + max) % max; // anti-clockwise data modification
            data[front] = x;
        }
    }
}

int deq::dequeatfront()
{
    int x;
    if (isempty())
    {
        cout << "queue is empty " << endl;
        return 0 ;
    }
    else
    {
        if (front == rear)
        {
            cout << "deleting last element" << endl;
            x = data[front];
            initialize();
            return x;
        }
        else
        {
            x = data[front];
            cout<<"front: "<<front<<endl ;
            front = (front + 1) % max; // clock-wise modification

            return x;
        }
    }
}

int deq::dequer()
{
    int y;
    if (isempty())
    {
        cout << "queue is empty " << endl;
    }
    else
    {
        if (front == rear)
        {
            cout << "deleting last element" << endl;
            y = data[rear];
            initialize();
            return y;
        }
        else
        {
            y = data[rear];
            cout<<"rear : "<<rear ;
            rear = (rear - 1 + max) % max; // anti-clockwise rotation
            return y;
        }
    }
}



int main()
{
    deq d1;
    int opt;
    do
    {
        cout << "1.Enter data from rear \n2.Enter data from front \n3.delete data from front\n4.delete data from rear \n5.To display \n6.to exit";
        cout << "\nEnter choice : " << endl;
        cin >> opt;
        switch (opt)
        {
        case 1:
            int x;
            cout << "enter element  :" << endl;
            cin >> x;
            d1.enqueR(x);
            break;
        case 2:
            int y;
            cout << "enter element  :" << endl;
            cin >> y;
            d1.enquef(y);
            break; 
        case 3:
            int x1;
            x1 = d1.dequeatfront();
            cout << "deleted element : " << x1 << endl;
            break;
        case 4:
            int key;
            key = d1.dequer();
            cout << "deleted element : " <<key<< endl;
            break;
        case 5:
            d1.display();
        
    }} while (opt != 6);
    return 0;
}
