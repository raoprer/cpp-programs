#include<iostream>
#define MAX_SIZE 10
using namespace std;

class TwoStack
{
    int top1,top2;
    int ts[MAX_SIZE];
public:
    TwoStack()
    {
        top1=-1;
        top2=MAX_SIZE;
    }
    bool isEmpty();
    void push1(int x);
    int pop1();
    void display1();
    void push2(int x);
    int pop2();
    void display2();
};

bool TwoStack::isEmpty()
{
    return (top1==-1 || top2==MAX_SIZE);
}

void TwoStack::push1(int x)
{
    if(top1>top2-1){
        cout<<"Stack overflow";
        return;
    }
    ts[++top1]=x;
}

int TwoStack::pop1()
{
    if(isEmpty()){
        cout<<"Stack underflow";
        return 0;
    }
    return ts[top1--];
}

void TwoStack::display1()
{
    for(int i=top1;i>=0;i--)
        cout<<ts[i]<<" ";
}

void TwoStack::push2(int x)
{
    if(top1>top2-1){
        cout<<"Stack overflow";
        return;
    }
    ts[--top2]=x;
}

int TwoStack::pop2()
{
    if(isEmpty()){
        cout<<"Stack underflow";
        return 0;
    }
    return ts[top2++];
}

void TwoStack::display2()
{
    for(int i=top2;i<MAX_SIZE;i++)
        cout<<ts[i]<<" ";
}

int main()
{
    TwoStack stk;
    int n=0;
    do{
        cout<<"Enter which stack do you want to enter into(1/2): ";
        int n;
        cin>>n;
        cout<<"What operation do you want to perform? ";
        cout<<"1:push 2:pop 3:display ";
        int o;
        cin>>o;
        switch(n)
        {
        case 1:
            switch(o)
            {
            case 1:
                int x;
                cin>>x;
                stk.push1(x);
                break;
            case 2:
                stk.pop1();
                break;
            case 3:
                stk.display1();
                break;
            }
        case 2:
              switch(o)
            {
            case 1:
                int x;
                cin>>x;
                stk.push2(x);
                break;
            case 2:
                stk.pop2();
                break;
            case 3:
                stk.display2();
                break;
            }
        }
    }while(n!=-1);
    return 0;
}
