#include<iostream>
using namespace std;

class Node
{
public:
    int info;
    Node* next;
    void insertBeg();
    void insertEnd();
    void insertPos();
    void deleteBeg();
    void deleteEnd();
    void deleteData();
    void Reverse();
    void sortByVal();
    void sortByNode();
    void print();
}*head;

void Node::insertBeg()
{
    Node* newNode=new Node;
    newNode->next=NULL;
    cout<<"Enter the value: ";
    cin>>newNode->info;
    if(!head){
        head=newNode;
    }
    else{
        newNode->next=head;
        head=newNode;
    }
}

void Node::insertEnd()
{
    Node* newNode=new Node;
    newNode->next=NULL;
    cout<<"Enter the value: ";
    cin>>newNode->info;
    if(!head){
        head=newNode;
    }
    else{
        Node* temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newNode;
    }
}

void Node::insertPos()
{
    Node* newNode=new Node;
    cout<<"Enter the position: ";
    int pos;
    cin>>pos;
    cout<<"Enter the value: ";
    cin>>newNode->info;
    if(!head)
        cout<<"List is empty!";
    else{
        Node* temp=head;
        int i=0;
        while(i!=pos-1 && temp->next!=NULL){
            temp=temp->next;
        }
        if(i==pos-1){
            newNode->next=temp->next;
            temp->next=newNode;
        }
        else{
            cout<<pos<<"Position not found"<<endl;
        }
    }
}

void Node::deleteBeg()
{
    if(head==NULL){
        cout<<"Empty list"<<endl;
        return;
    }
    Node* temp=head;
    head=head->next;
    delete(temp);
}

void Node::deleteEnd()
{
    if(head==NULL){
        cout<<"Empty list"<<endl;
        return;
    }
    Node* temp=head;
    while(temp->next->next!=NULL)
        temp=temp->next;
    Node* t=temp->next->next;
    temp->next=NULL;
    delete(t);
}

void Node::deleteData()
{
    Node* temp=head;
    if(!head)
        cout<<"Empty list";
    else{
        int data;
        cout<<"Enter the value: ";
        cin>>data;
        while(temp!=NULL && temp->next->info!=data){
            temp=temp->next;
        }
        Node* t=temp->next;
        if(t==head){
            head=head->next;
        }
        else if(t==NULL){
            cout<<"No record found"<<endl;
        }
        else{
            temp->next=temp->next->next;
        }
        delete(t);
    }
}

void Node::Reverse()
{
    Node* temp=head;
    Node* nxt=head->next;
    Node* prev=head;
    temp->next=NULL;
    while(nxt!=NULL){
        temp=nxt;
        nxt=temp->next;
        temp->next=prev;
        prev=temp;
    }
    head=temp;
}

void Node::sortByVal()
{
    if(!head){
        cout<<"Empty list"<<endl;
        return;
    }
    Node* i=head;
    while(i){
        Node* j=i->next;
        while(j){
            if(i->info>j->info){
                int temp=i->info;
                i->info=j->info;
                j->info=temp;
            }
            j=j->next;
        }
        i=i->next;
    }
}

void Node::sortByNode()
{
    if(!head){
        cout<<"Empty list"<<endl;
        return;
    }
    Node* i=head;
    Node* previ=NULL;
    while(i->next!=NULL){
        Node* j=i->next;
        Node* prevj=i;
        while(j->next!=NULL){
            if(i->info>j->info){
                Node* temp=i->next;
                i->next=j->next;
                j->next=temp;
                previ->next=j;
                prevj->next=i;
                temp=NULL;
                delete(temp);
            }
            prevj=j;
            j=j->next;
        }
        previ=i;
        i=i->next;
    }
}

void Node::print()
{
    Node* temp=head;
    if(temp==NULL)
        cout<<"Empty list";
    while(temp!=NULL){
        cout<<"->"<<temp->info;
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    Node n;
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
            n.Reverse();
            break;
        case 8:
            n.sortByVal();
            break;
        case 9:
            n.sortByNode();
            break;
        case 10:
            n.print();
            break;
        case 11:
            c=-1;
            break;
        }
    }while(c!=-1);
}
