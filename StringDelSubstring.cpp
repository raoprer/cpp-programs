#include<iostream>
using namespace std;

int main()
{
    char str[20],sub[20];
    cout<<"Enter the string: ";
    cin>>str;
    cout<<"Enter the string to be deleted: ";
    cin>>sub;

    int lenStr=0;
    for(;str[lenStr]!='\0';lenStr++);
    int lenSub=0;
    for(;sub[lenSub]!='\0';lenSub++);

    int len=lenStr-lenSub;
    for(int i=0;i<len+1;i++){
        int k=0,flag=1;
        for(int j=i;j<lenSub+i;j++){
            if(str[j]!=sub[k++]){
                flag=0;
                break;
            }
        }
        if(flag){
            int j;
            for(j=i;str[j]!='\0';j++){
                str[j]=str[j+lenSub];
            }
            str[j]='\0';
        }
        len-=lenSub;
    }
    str[len]='\0';
    cout<<"The modified string is: "<<str;
    return 0;
}
