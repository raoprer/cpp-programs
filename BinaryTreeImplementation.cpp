#include<iostream>
#include<string.h>
#define MAX 10
using namespace std;

class node
{
public:
    int data;
    node* ll;
    node* rl;
    node* next;
};

class Stack
{
    node* top;
public:
    Stack()
    {
        top=NULL;
    }
    bool isEmpty()
    {
        return (top==NULL);
    }
    void push(node* ele)
    {
        if(top==NULL){
            top=ele;
            return;
        }
        ele->next=top;//insert at the beginning
        top=ele;
    }
    node* pop()
    {
        if(top==NULL){
            //cout<<"Empty stack"<<endl;
            return NULL;
        }
        node *temp=top;
        top=top->next;
        temp->next=NULL;
        return temp;
    }
    node* peek()
    {
        if(top==NULL)
            return NULL;
        return top;
    }
};

class Queue
{
    int f,r;
    node *q[MAX];
public:
    Queue()
    {
        f=r=-1;
    }
    bool isEmpty()
    {
        return (f==r);
    }
    void push(node* ele)
    {
        if(isEmpty()){
            return;
        }
        q[++r]=ele;
    }
    node* pop()
    {
        if(r==MAX){
            return NULL;
        }
        return q[++f];
    }
};

//Insertion
node* insertNode(node* root)
{
    node *newNode,*cur,*prev;
    newNode=new node;
    int item;
    cout<<"Enter the value: ";
    cin>>item;
    newNode->data=item;
    newNode->ll=newNode->rl=newNode->next=NULL;
    if(root==NULL){
        return newNode;
    }
    else{
        prev=NULL;
        cur=root;
        char d[20];
        cout<<"Enter the direction: ";
        cin>>d;
        int i;
        for(i=0;i<strlen(d);i++){
            if(cur==NULL)//imp
                break;
            prev=cur;
            cur=(d[i]=='l')?cur->ll:cur->rl;
        }
        if(cur!=NULL||strlen(d)!=i){
            cout<<"Impossible"<<endl;
            delete(newNode);
            return root;
        }
        if(d[i-1]=='l'){
            prev->ll=newNode;
        }
        else{
            prev->rl=newNode;
        }
    }
    return root;
}

//Recursive traversals
void preorder(node* root)
{
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->ll);
        preorder(root->rl);
    }
}

void inorder(node* root)
{
    if(root!=NULL){
        inorder(root->ll);
        cout<<root->data<<" ";
        inorder(root->rl);
    }
}

void postorder(node* root)
{
    if(root!=NULL){
        postorder(root->ll);
        postorder(root->rl);
        cout<<root->data<<" ";
    }
}

//Iterative traversals
void preorder_itr(node* root)
{
    Stack *s=new Stack;
    for(;;){
        for(;root;root=root->ll){
            cout<<root->data<<" ";
            s->push(root);
        }
        root=s->pop();
        if(root==NULL)break;
        root=root->rl;
    }
}

void inorder_itr(node* root)
{
    Stack *s=new Stack;
    for(;;){
        for(;root;root=root->ll){
            s->push(root);
        }
        root=s->pop();
        if(root==NULL) break;
        cout<<root->data<<" ";
        root=root->rl;
    }
}

void postorder_itr(node* root)
{
    Stack *s=new Stack;
    do{
        for(;root;root=root->ll){
            if(root->rl)
                s->push(root->rl);
            s->push(root);
        }
        root=s->pop();
        if(root==NULL) break;
        node* n=s->peek();
        if(n==NULL){
            cout<<root->data<<" ";
        }
        else if(root->rl && n->data==root->rl->data){
            s->pop();
            s->push(root);
            root=root->rl;
        }
        else{
            cout<<root->data<<" ";
            root=NULL;
        }
    }while(!s->isEmpty());
}

/*void levelorder(node* root)
{
    Queue q=new Queue;
    q.push(root);
    for(;;){
        root=q.pop();
        if(root){
            cout<<root->data<<" ";
            if(root->ll!=NULL){
                q.push(root->ll);
            }
            if(root->rl!=NULL){
                q.push(root->rl);
            }
        }
        else
            break;
    }
}*/

//Recursive search
void Search(node* root,int se,int *flag)
{
    if(root){
        Search(root->ll,se,flag);
        if(root->data==se){
            *flag=1;
            return;
        }
        Search(root->rl,se,flag);
    }
}

//Display
void display(node* root,int level)
{
    if(root){
        display(root->rl,level+1);
        for(int i=0;i<level;i++)
            cout<<"     ";
        cout<<root->data<<endl;
        display(root->ll,level+1);
    }
}

int noOfLeaf(node* root)
{
    if(root==NULL)
        return 0;
    else if(!root->ll & !root->rl)
        return 1;
    else
        return noOfLeaf(root->ll)+noOfLeaf(root->rl);
}

int main()
{
    node *root;//Just create pointer
    root=NULL;
    cout<<"1.Insert 2.Display recursive 3.Display iterative 4.Search 5.Display 6.Number of leaf nodes"<<endl;
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
            cout<<"Preorder: ";preorder(root);cout<<endl;
            cout<<"Inorder: ";inorder(root);cout<<endl;
            cout<<"Postorder: ";postorder(root);cout<<endl;
            break;
        case 3:
            cout<<"Preorder: ";preorder_itr(root);cout<<endl;
            cout<<"Inorder: ";inorder_itr(root);cout<<endl;
            cout<<"Postorder: ";postorder_itr(root);cout<<endl;
            //cout<<"Levelorder: ";levelorder(root);cout<<endl;
            break;
        case 4:
            cout<<"Enter the element to be searched: ";
            int se;
            cin>>se;
            int *flag;
            Search(root,se,flag);
            if(*flag==1){
                cout<<se<<" found"<<endl;
            }
            else
                cout<<se<<" not found"<<endl;
            break;
        case 5:
            cout<<"Number of leaves: "<<noOfLeaf(root)<<endl;
            break;
        case 6:
            int level=0;
            display(root,level);
            break;
        }
    }while(c!=0);
}
