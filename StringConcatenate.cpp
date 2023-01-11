#include<iostream>
using namespace std;

int main()
{
    char s1[30],s2[30];
    int i,j;

    cout<<"Enter the string 1: ";
    cin>>s1;
    cout<<"Enter the string 2: ";
    cin>>s2;

    for(i=0;s1[i]!='\0';i++);
    for(j=0;j<s2[j]!='\0';j++)
        s1[i++]=s2[j];
    s1[i++]='\0';

    cout<<s1;
    return 0;
}
