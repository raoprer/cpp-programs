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
    void transpose(smt s[],smt t[])
    {
        t[0].col=s[0].row;
        t[0].row=s[0].col;
        t[0].val=s[0].val;
        int i,j,ci=1;
        for(i=0;i<=col;i++){
            for(j=1;j<s[0].val;j++){
                if(i==s[j].col){
                    t[ci].col=s[j].row;
                    t[ci].row=s[j].col;
                    t[ci].val=s[j].val;
                    ci++;
                }
            }
        }
    }
};

int main()
{
    smt s[MAX],t[MAX],a;
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
    a.transpose(s,t);
    cout<<"Transpose of the given matrix is:\n";
    k=1;
    for(int i=0;i<t[0].row;i++){
        for(int j=0;j<t[0].col;j++){
            if(t[k].row==i && t[k].col==j){
                cout<<t[k].val<<" ";
                k++;
            }
            else
                cout<<"0 ";
        }
        cout<<"\n";
    }
    return 0;
}
