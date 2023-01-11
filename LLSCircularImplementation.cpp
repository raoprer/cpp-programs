#include<iostream>
using namespace std;

class cnode
{
public:
    int info;
    cnode* next;
    void insertBeg();
    void insertEnd();
    void insertPos();
    void deleteBeg();
    void deleteEnd();
    void deleteData();
    void print();
}*tail;

void cnode::insertBeg()
{
    cnode *newNode=new cnode;
    newNode->next=NULL;
    cout<<"Enter the value: ";
    cin>>newNode->info;
    if(tail==NULL){
     tail=newNode;
     newNode->next=tail;
    }
    else{
        newNode->next=tail->next;
        tail->next=newNode;
    }
}

void cnode::insertEnd()
{
    cnode *newNode=new cnode;
    newNode->next=NULL;
    cout<<"Enter the value: ";
    cin>>newNode->info;
    if(tail==NULL)
        tail=newNode;
    else{
        newNode->next=tail->next;
        tail->next=newNode;
        newNode=tail;
    }
}

void cnode::insertPos()
{
    cnode *newNode=new cnode;
    newNode->next=NULL;
    cout<<"Enter the position: ";
    int pos;
    cin>>pos;
    cout<<"Enter the value: ";
    cin>>newNode->info;
    if(tail==NULL)
       tail=newNode;
    else{
        cnode *temp=tail;
        for(int i=1;i<pos;i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
}

void cnode::deleteBeg()
{
    cnode *temp=tail->next;
    if(tail==NULL)
        cout<<"Empty list"<<endl;
    else{
        tail->next=temp->next;
        delete(temp);
    }
}

void cnode::deleteEnd()
{
    cnode *temp=tail;
    if(tail==NULL)
        cout<<"List is empty"<<endl;
    else{
        cnode *t=temp;
        while(temp->next!=tail)
            temp=temp->next;
        temp->next=tail->next;
        tail=temp;
        delete(t);
    }
}

void cnode::deleteData()
{
    cnode *temp=tail;
    if(tail==NULL)
        cout<<"Empty list"<<endl;
    else{
        cout<<"Enter the value: ";
        int data;
        cin>>data;
        cnode *temp=tail;
        cnode *t=temp->next;
        while(temp->next->info!=data){
            temp=temp->next;
            t=temp->next;
            if(t==tail){
                cout<<"No record found"<<endl;
            }
        }
        temp->next=t->next;
        delete(t);
    }
}

void cnode::print()
{
    if(tail==NULL)
        cout<<"List is empty"<<endl;
    else{
        cnode *temp=tail->next;
        while(temp->next!=tail){
            cout<<"->"<<temp->info;
            temp=temp->next;
        }
        cout<<"->"<<tail->info;
    }
}

int main()
{
    cnode n;
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
            n.print();
            break;
        case 8:
            c=-1;
            break;
        }
    }while(c!=-1);
}
