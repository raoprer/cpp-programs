#include<iostream>
using namespace std;

int main()
{
    char str[30],sub[20],temp[30];
    int location,i,j;

    cout<<"Enter the string: ";
    cin>>str;
    cout<<"Enter the substring: ";
    cin>>sub;
    cout<<"Enter the location of the insertion: ";
    cin>>location;

    for(i=0;str[i]!='\0';i++)
        temp[i]=str[i];
    temp[i]='\0';

    for(i=0;sub[i]!='\0';i++)
        str[i+location]=sub[i];

    int subLen=0;
    for(;sub[subLen]!='\0';subLen++);

    for(j=location;temp[j]!='\0';j++)
        str[j+subLen]=temp[j];
    str[j+subLen+1]='\0';

    cout<<"The modified string is: ";
    cout<<str;

    return 0;
}
