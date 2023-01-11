#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* ll;
    node* rl;
};

node* insertNode(node* root)
{
    node *newNode,*cur,*prev;
    newNode=new node;
    cout<<"Enter the value: ";
    int item;//imp
    cin>>item;
    newNode->data=item;
    newNode->ll=newNode->rl=NULL;
    if(!root){
        return newNode;
    }
    cur=root;
    prev=NULL;
    while(cur!=NULL){//imp
        prev=cur;
        cur=(item<cur->data)?cur->ll:cur->rl;
    }
    if(item<prev->data)
        prev->ll=newNode;
    else
        prev->rl=newNode;
    return root;
}

int Search(node *root,int se)
{
    while(root!=NULL){
        if(root->data==se)
            return 1;
        root=(se<root->data)?root->ll:root->rl;
    }
    return 0;
}

void display(node* root,int level)
{
    if(root!=NULL){
        display(root->rl,level+1);
        for(int i=0;i<level;i++)
            cout<<"     ";
        cout<<root->data<<endl;
        display(root->ll,level+1);
    }
}

void DeleteNode(node* root,int val)
{
    if(!root)
        return;
    node* prev,*cur,*succ;
    cur=prev=NULL;
    node* q=root;
    while(q!=NULL){
        if(q->data==val){
            cur=q;
            break;
        }
        prev=q;
        if(val<q->data)
            q=q->ll;
        else
            q=q->rl;
    }
    //here cur points to the obj to be deleted and prev previous to it
    if(!cur->ll && !cur->rl){
        if(prev->ll==cur)
            prev->ll=NULL;
        else
            prev->rl=NULL;
    }
    else if(!cur->ll && cur->rl){
        if(prev->ll==cur)
            prev->ll=cur->rl;
        else
            prev->rl=cur->ll;
    }
    else if(cur->ll && !cur->rl){
        if(prev->ll==cur)
            prev->ll=cur->ll;
        else
            prev->rl=cur->ll;
    }
    else{
        prev=cur;
        succ=cur->rl;
        while(succ->ll!=NULL){
            prev=succ;
            succ=succ->ll;
        }
        int val=succ->data;
        DeleteNode(root,val);
        cur->data=val;
    }
}

int main()
{
    node *root;
    root=NULL;
    cout<<"1.Insert 2.Search 3.Delete 4.Display"<<endl;
    int c;
    do{
        cout<<"> ";
        cin>>c;
        switch(c)
        {
        case 1:
            root=insertNode(root);
            break;
        case 2:
            int se;
            cout<<"Enter the value: ";
            cin>>se;
            if(Search(root,se))
                cout<<se<<" found"<<endl;
            else
                cout<<se<<" not found"<<endl;
            break;
        case 3:
            int item;
            cout<<"Enter the element to be deleted: ";
            cin>>item;
            DeleteNode(root,item);
            break;
        case 4:
            int level=0;
            display(root,level);
            break;
        }
    }while(c!=0);
}
