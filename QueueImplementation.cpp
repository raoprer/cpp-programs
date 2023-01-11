#include<iostream>
#define MAX 10
using namespace std;

class Queue
{
    int f,r;
    int q[MAX];
public:
    Queue()
    {
        f=r=-1;
    }
    bool isEmpty();
    bool isFull();
    void Insert(int x);
    int Delete();
    void display();
};

bool Queue::isEmpty()
{
    return (f==r);
}

bool Queue::isFull()
{
    return (r==MAX-1);
}

void Queue::Insert(int x)
{
    if(isFull())
        cout<<"Queue is full";
    else
        q[++r]=x;
}

int Queue::Delete()
{
    if(isEmpty()){
        cout<<"Queue is empty";
        return 0;
    }
    return q[++f];
}

void Queue::display()
{
    for(int i=f+1;i<=r;i++)
        cout<<q[i]<<" ";
}

int main()
{
    Queue que;
    cout<<"Enter what operation would you like to perform on the Queue?\n";
    cout<<"1:Insert 2:Delete 3:display\n";
    int in;
    do{
        cin>>in;
        switch(in)
        {
        case 1:
            int x;
            cout<<"Enter the element: ";
            cin>>x;
            que.Insert(x);
            break;
        case 2:
            cout<<que.Delete();
            cout<<" ";
            break;
        case 3:
            que.display();
        }
    }while(in!=-1);
    return 0;
}
