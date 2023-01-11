#include<iostream>
using namespace std;

int rev(int n)
{
    static int revOfNum=0;
    if(n==0)
        return revOfNum;
    revOfNum=revOfNum*10+n%10;
    return rev(n/10);
}

int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"The reversed number is :"<<rev(n);
    return 0;
}
