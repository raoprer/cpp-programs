#include<iostream>
using namespace std;

class dcnode
{
    int info;
    dcnode *next;
    dcnode *prev;
public:
    void insertBeg();
    void insertEnd();
    void insertPos();
    void deleteBeg();
    void deleteEnd();
    void deleteData();
    void printA();
    void printD();
}*tail;

void dcnode::insertBeg()
{
    dcnode *newNode=new dcnode;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(!tail)
        tail=newNode;
    else{
        cout<<"Enter the value: ";
        cin>>newNode->info;
        newNode->prev=tail;
        newNode->next=tail->next;
        tail->next=newNode;
    }
}

void dcnode::insertEnd()
{
    dcnode newNode=new dcnode;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(!tail)
        tail=newNode;
    else{
        newNode->next=tail->next;
        newNode->prev=tail;
        tail->next=newNode;
        tail=newNode;
    }
}
