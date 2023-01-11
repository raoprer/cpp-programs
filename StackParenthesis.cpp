#include<iostream>
#include<string.h>
#define MAX_SIZE 10
using namespace std;

class Stack
{
    int top;
    int s[MAX_SIZE];
public:
    Stack()
    {
        top=-1;
    }
    bool isEmpty();
    void push(char x);
    int pop();
    int peek();
};

bool Stack::isEmpty()
{
    return (top==-1);
}

void Stack::push(char x)
{
    if(top>=MAX_SIZE){
        cout<<"Stack overflow";
        return;
    }
    s[++top]=x;
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
    if(isEmpty())
        return 0;
    return s[top];
}

int main()
{
    Stack stk;
    cout<<"Enter the expression: ";
    string exp;
    cin>>exp;
    //Push the left parenthesis into the stack
    int match=1;
    for(int i=0;exp[i]!='\0' && match==1;i++){
        switch(exp[i])
        {
        case '{':
            stk.push(exp[i]);
            break;
        case '[':
            stk.push(exp[i]);
            break;
        case '(':
            stk.push(exp[i]);
            break;
        case '}':
            if(stk.peek()=='{')
                stk.pop();
            else
                match=0;
            break;
        case ']':
            if(stk.peek()=='[')
                stk.pop();
            else
                match=0;
            break;
        case ')':
            if(stk.peek()=='(')
                stk.pop();
            else
                match=0;
            break;
        }
    }
    if(match && stk.isEmpty())
        cout<<"Valid expression";
    else
        cout<<"Invalid expression";
    return 0;
}
