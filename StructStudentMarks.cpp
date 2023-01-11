#include<iostream>
using namespace std;

struct student
{
    char name[20];
    int rno;
    int marks[10];
    int tot=0;
}s[20];

int main()
{
    int s_no,m_no;
    cout<<"Enter the number of students: ";
    cin>>s_no;
    cout<<"Enter the number of subjects: ";
    cin>>m_no;

    for(int i=0;i<s_no;i++){
        cout<<"Enter the name and roll number of "<<i+1<<"th student: ";
        cin>>s[i].name;
        cin>>s[i].rno;
        for(int j=0;j<m_no;j++){
            cout<<"Enter "<<s[i].name<<"'s mark in "<<j+1<<"th subject: ";
            cin>>s[i].marks[j];
            s[i].tot+=s[i].marks[j];
        }
    }

    for(int i=0;i<s_no-1;i++){
        for(int j=0;j<s_no-i-1;j++){
            if(s[j].tot>s[j+1].tot){
                student temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
    cout<<"The highest scorer is "<<s[s_no-1].name<<", roll no "<<s[s_no-1].rno<<endl;
    cout<<"The second highest scorer is "<<s[s_no-2].name<<", roll no "<<s[s_no-2].rno<<endl;

    return 0;
}
