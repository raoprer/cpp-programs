#define MAX 10
#include<iostream>
#include<string.h>
using namespace std;

class Stack
{
    int top;
    char s[MAX];
public:
    Stack()
    {
        top=-1;
    }
    bool isEmpty();
    bool isFull();
    void push(char x);
    char pop();
    char peek();
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

void Stack::push(char x)
{
    if(isFull()){
        cout<<"Stack overflow";
        return;
    }
    s[++top]=x;
    return;
}

char Stack::pop()
{
    if(isEmpty()){
        cout<<"Stack underflow";
        return 0;
    }
    return s[top--];
}

char Stack::peek()
{
    if(isEmpty()){
        cout<<"Empty stack";
        return 0;
    }
    return s[top];
}

void Stack::display()
{
    for(int i=top;i>0;i--)
        cout<<s[i];
}

int main()
{
    Stack stk;
    cout<<"Enter the string: ";
    char str[MAX];
    cin>>str;
    for(int i=0;str[i]!='\0';i++)
        stk.push(str[i]);
    int i=0;
    char rev[MAX];
    while(!stk.isEmpty()){
        rev[i++]=stk.pop();
    }
    rev[i]='\0';
    if(!strcmp(str,rev))
        cout<<str<<" is a palindrome";
    else
        cout<<str<<" is not a palindrome";
    return 0;
}
