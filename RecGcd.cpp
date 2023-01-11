#include<iostream>
using namespace std;

int gcd(int a,int b)
{
    if(a==0)
        return b;
    if(b==0)
        return a;
    return rec(b,a%b);
}

int main()
{
    int a,b;
    cout<<"Enter 2 numbers: ";
    cin>>a>>b;
    cout<<"The gcd of"<<a<<" and "<<b<<"is "<<gcd(a,b);
    return 0;
}
