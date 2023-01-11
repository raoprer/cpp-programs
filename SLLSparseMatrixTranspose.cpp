#include<iostream>
using namespace std;

class SM
{
public:
    int r,c,val;
    void createSM(int row,int col,int value)
    {
        r=row;
        c=col;
        val=value;
    }
};

class node
{
    SM data;
    node* next;
public:
    node* Insert(node* head,int i,int j,int value)
    {
        node *newNode=new node;
        (newNode->data).createSM(i,j,value);
        newNode->next=NULL;
        if(head==NULL){
            return newNode;
        }
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        return head;
    }
    void print(node* head)
    {
        node* temp=head;
        while(temp!=NULL){
            cout<<"< "<<(temp->data).r<<" "<<(temp->data).c<<" "<<(temp->data).val<<" >"<<endl;
            temp=temp->next;
        }
    }
    node* transpose(node* head,node* tran)
    {
        if(!head)
            return tran;
        //swapping
        node* temp=head;
        while(temp!=NULL){
            tran=tran->Insert(tran,temp->data.c,temp->data.r,temp->data.val);
        }
        //sorting
        temp=tran;
        while(temp->next!=NULL){
            node* nxt=temp->next;
            while(nxt!=NULL){
                if(temp->data.r>nxt->data.r){
                    SM Swap=temp->data;
                    temp->data=nxt->data;
                    nxt->data=Swap;
                }
                nxt=nxt->next;
            }
            temp=temp->next;
        }
        return tran;
    }
};

int main()
{
    node *head=NULL;
    node *tran=NULL;
    cout<<"Enter the rows cols and non zero vals: ";
    int row,col,value;
    cin>>row>>col>>value;
    cout<<"Enter the matrix:"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>value;
            if(value!=0){
                head=head->Insert(head,i,j,value);
            }
        }
    }
    cout<<endl;
    cout<<"\nSparse matrix:"<<endl;
    head->print(head);
    tran=tran->transpose(head,tran);
    cout<<"\nTranspose:"<<endl;
    tran->print(tran);
}
