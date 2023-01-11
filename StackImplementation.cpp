#include<iostream>
#define MAX 10
using namespace std;

class Stack
{
    int top;
    int a[MAX];
public:
    Stack()
    {
        top=-1;
    }
    bool isEmpty();
    bool isFull();
    bool push(int x);
    int pop();
    int peek();
    void display();
};

bool Stack::isEmpty()
{
    return (top<0);
}

bool Stack::isFull()
{
    return (top>=MAX);
}

bool Stack::push(int x)
{
    if(top>=MAX-1){
        cout<<"Stack overflow";
        return false;
    }
    else{
        a[++top]=x;
        return true;
    }
}

int Stack::pop()
{
    if(isEmpty()){
        cout<<"Stack underflow";
        return 0;
    }
    else{
        return a[top--];
    }
}

int Stack::peek()
{
    if(isEmpty()){
        cout<<"Stack is empty";
        return 0;
    }
    else{
        return a[top];
    }
}

void Stack::display()
{
    for(int i=top;i>=0;i--)
        cout<<a[i];
        cout<<" ";
}

int main()
{
    Stack stk;
    cout<<"Enter what operation would you like to perform on the stack?\n";
    cout<<"1:Push 2:Pop 3:Peek 4:display\n";
    int in;
    do{
        cin>>in;
        switch(in)
        {
        case 1:
            int x;
            cout<<"Enter the element: ";
            cin>>x;
            stk.push(x);
            break;
        case 2:
            cout<<stk.pop();
            cout<<" ";
            break;
        case 3:
            cout<<stk.peek();
            cout<<" ";
            break;
        case 4:
            stk.display();
        }
    }while(in!=-1);
    return 0;
}
