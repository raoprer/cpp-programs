#include<iostream>
#define MAX 10
using namespace std;

class smt
{
public:
    int row,col,val;
    void createSm(int r,int c,int value)
    {
        row=r;
        col=c;
        val=value;
    }
};

int main()
{
    smt s[MAX];
    cout<<"Enter the number of rows and columns: ";
    int r,c;
    int value,k=1;
    cin>>r>>c;
    cout<<"Enter the elements:\n";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>value;
            if(value!=0){
                s[k++].createSm(i,j,value);
            }
        }
    }
    s[0].createSm(r,c,k-1);
    cout<<"The sparse matrix representation is:\n";
    for(int i=0;i<=k-1;i++){
        cout<<s[i].row<<" "<<s[i].col<<" "<<s[i].val<<endl;
    }
    k=1;
    cout<<"The actual matrix is:\n";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(s[k].row==i && s[k].col==j){
                cout<<s[k].val<<" ";
                k++;
            }
            else
                cout<<"0 ";
        }
        cout<<"\n";
    }
    return 0;
}
