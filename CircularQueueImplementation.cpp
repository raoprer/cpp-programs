#include<iostream>
#define n 10
using namespace std;

class cqueue
{
    int f,r;
    int cq[10];
public:
    cqueue()
    {
        f=r=-1;
    }
    bool isEmpty();
    bool isFull();
    void Insert(int x);
    int Delete();
    void display();
};

bool cqueue::isEmpty()
{
    return (f==r);
}

bool cqueue::isFull()
{
    return ((n+r-f)%n==n-1);
}

void cqueue::Insert(int x)
{
    if(isFull())
        cout<<"Queue is full";
    else
        cq[++r%n]=x;
}

int cqueue::Delete()
{
    if(isEmpty()){
        cout<<"Queue is empty";
        return 0;
    }
    return cq[++f%n];
}

void cqueue::display() //Some prob in display function
{
    for(int i=f+1;i<=r;i++)
        cout<<cq[i]<<" ";
}

int main()
{
    cqueue cque;
    cout<<"Enter what operation would you like to perform on the circular queue?\n";
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
            cque.Insert(x);
            break;
        case 2:
            cout<<cque.Delete();
            cout<<" ";
            break;
        case 3:
            cque.display();
        }
    }while(in!=-1);
    return 0;
}
