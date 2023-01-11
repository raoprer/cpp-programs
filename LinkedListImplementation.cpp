#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class LinkedList
{
    Node* head;
public:
    LinkedList()
    {
        head=NULL;
    }
    void Insert(int data);
    void Delete(int pos);
    void display();
    void Reverse();
};

void LinkedList::Insert(int data)
{
    Node* node=new Node;
    node->data=data;
    node->next=NULL;

    if(!head)
        head=node;
    else{
        Node* temp=head;
        while(temp->next)
            temp=temp->next;
        temp->next=node;
    }
}

void LinkedList::display()
{
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void LinkedList::Delete(int pos)//pos in 0 based numbering
{
    Node* temp=head;
    int i=0;
    for(;i<pos-1;i++){
        temp=temp->next;
    }
    (temp->next)=(temp->next->next);
}

void LinkedList::Reverse()
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

int main()
{
    LinkedList ll;
    ll.Insert(1);
    ll.Insert(2);
    ll.Insert(3);
    ll.display();
    ll.Delete(2);
    ll.display();
    ll.Reverse();
    ll.display();
    return 0;
}
