#include<iostream>
using namespace std;

int sum(int n)
{
    if(n==0)
        return 0;
    return sum(n/10)+n%10;
}

int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"The sum of digits of the number is :"<<sum(n);
    return 0;
}
