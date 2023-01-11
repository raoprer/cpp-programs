#include<iostream>
using namespace std;

class dnode
{
    int info;
    dnode* next;
    dnode* prev;
public:
    void insertBeg();
    void insertEnd();
    void insertPos();
    void deleteBeg();
    void deleteEnd();
    void deleteData();
    void printA();
    void printD();
}*head;

void dnode::insertBeg()
{
    dnode *newNode=new dnode;
    newNode->next=NULL;
    newNode->prev=NULL;
    cout<<"Enter the value: ";
    cin>>newNode->info;
    if(!head)
        head=newNode;
    else{
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
}

void dnode::insertEnd()
{
    dnode *newNode=new dnode;
    newNode->next=NULL;
    newNode->prev=NULL;
    cout<<"Enter the value: ";
    cin>>newNode->info;
    if(!head)
        head=newNode;
    else{
        dnode* temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newNode;
        newNode->prev=temp;
    }
}

void dnode::insertPos()
{
    dnode *newNode=new dnode;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(!head)
        cout<<"List is empty"<<endl;
    else{
        cout<<"Enter the position: ";
        int pos;
        cin>>pos;
        cout<<"Enter the value: ";
        cin>>newNode->info;
        dnode *temp=head;
        for(int i=1;i<pos-1;i++)
            temp=temp->next;
        newNode->next=temp->next;
        newNode->prev=temp;
        temp->next->prev=newNode;
        temp->next=newNode;
    }
}

void dnode::deleteBeg()
{
    if(!head)
        cout<<"Empty list"<<endl;
    else{
        dnode *t=head;
        head=head->next;
        head->prev=NULL;
        delete(t);
    }
}

void dnode::deleteEnd()
{
    if(!head)
        cout<<"Empty list"<<endl;
    else{
        dnode *temp=head;
        while(temp->next->next!=NULL)
            temp=temp->next;
        dnode *t=temp->next;
        temp->next=NULL;
        delete(t);
    }
}

void dnode::deleteData()
{
    if(!head)
        cout<<"Empty list"<<endl;
    else{
        cout<<"Enter the value: ";
        int data;
        cin>>data;
        dnode *temp=head;
        while(temp->next->info!=data)
            temp=temp->next;
        dnode *t=temp->next;
        if(t==head){
            head=head->next;
            head->prev=NULL;
        }
        else if(t==NULL)
            cout<<"No record found"<<endl;
        else if(t->next==NULL)
            temp->next=NULL;
        else{
            temp->next=temp->next->next;
            temp->next->prev=temp->next->prev->prev;
        }
        delete(t);
    }
}

void dnode::printA()
{
    dnode *temp=head;
    if(!head)
        cout<<"List is empty"<<endl;
    else{
        while(temp!=NULL){
            cout<<"->"<<temp->info;
            temp=temp->next;
        }
        cout<<endl;
    }
}

void dnode::printD()
{
    dnode *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    while(temp!=NULL){
        cout<<"->"<<temp->info;
        temp=temp->prev;
    }
    cout<<endl;
}

int main()
{
    dnode n;
    int c;
    do{
        cout<<"Enter your choice: ";
        cin>>c;
        switch(c)
        {
        case 1:
            n.insertBeg();
            break;
        case 2:
            n.insertEnd();
            break;
        case 3:
            n.insertPos();
            break;
        case 4:
            n.deleteBeg();
            break;
        case 5:
            n.deleteEnd();
            break;
        case 6:
            n.deleteData();
            break;
        case 7:
            n.printA();
              break;
        case 8:
            n.printD();
            break;
        case 9:
            c=-1;
            break;
        }
    }while(c!=-1);
}

