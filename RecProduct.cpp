#include<iostream>
using namespace std;

int prod(int a,int b)
{
    if(a==0 || b==0)
        return 0;
    if(a>b)
        return a+prod(a,b-1);
    else
        return b+prod(a-1,b);
}

int main()
{
    int a,b;
    cout<<"Enter 2 numbers: ";
    cin>>a>>b;
    cout<<"The product of "<<a<<" and "<<b<<" is "<<prod(a,b);
    return 0;
}
