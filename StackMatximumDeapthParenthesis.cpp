//((((x)))((((y)))))
#include<iostream>
#define N 20
using namespace std;

class Stack
{
    int s[N];
public:
    int top;
    Stack()
    {
        top=-1;
    }
    void push(int x)
    {
        if(top==N)
            cout<<"Stack is full";
        else
            s[++top]=x;
    }
    int pop()
    {
        if(top==-1){
            cout<<"Stack is empty";
            return -1;
        }
        return s[top--];
    }
    int peek()
    {
        if(top!=-1)
            return s[top];
        else{
            cout<<"Stack is empty";
            return -1;
        }
    }
};
int main()
{
    Stack stk;
    char exp[N];
    int a[N];
    int j=-1,t=stk.top;
    cout<<"Enter the expression: ";
    cin>>exp;
    for(int i=0;exp[i]!='\0';i++){
        char c=exp[i];
        if(c=='(')
            stk.push(c);
        else if(c>='A' && c<='Z' || c>='a' && c<='z'){
            j++;
        }
        else if(c==')'){
            if(stk.peek()=='('){
                a[j]++;
                stk.pop();
            }
        }
    }
    int large=a[0];
    for(int i=0;i<=j;i++){
        if(a[i]>large)
            large=a[i];
    }
    cout<<"Large is: "<<large;
    return 0;
}
