#include<iostream>
#define MAX 10
using namespace std;

class Stack
{
    int top;
    int s[MAX];
public:
    Stack()
    {
        top=-1;
    }
    bool isEmpty();
    bool isFull();
    void push(int x);
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

void Stack::push(int x)
{
    if(isFull()){
        cout<<"Stack overflow";
        return;
    }
    s[++top]=x;
    return;
}

int Stack::pop()
{
    if(isEmpty()){
        cout<<"Stack underflow";
        return 0;
    }
    return s[top--];
}

int Stack::peek()
{
    if(isEmpty()){
        cout<<"Stack is empty";
        return 0;
    }
    return s[top];
}

void Stack::display()
{
    if(isEmpty()){
        cout<<"Stack is empty";
        return ;
    }
    for(int i=top;i>=0;i--)
        cout<<s[i];
}

int main()
{
    Stack stk;
    cout<<"Enter the number in decimal: ";
    int d;
    cin>>d;
    cout<<"which base do you want to convert "<<d<<" to?";
    int b;
    cin>>b;
    int n=d;
    while(n>0){
        stk.push(n%b);
        n/=b;
    }
    stk.display();
    return 0;
}
