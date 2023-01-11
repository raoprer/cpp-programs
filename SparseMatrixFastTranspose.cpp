#include<iostream>
#define MAX 20
using namespace std;

class smt
{
public:
    int row,col,val;
    void createSm(int r,int c,int value);
    void fastTranspose(smt s[],smt t[]);
};

void smt::createSm(int r,int c,int value)
{
    row=r;
    col=c;
    val=value;
}

void smt::fastTranspose(smt s[],smt t[])
{
    int ri[MAX],sl[MAX];
    int nt=s[0].val;
    int i,j;
    for(i=0;i<col;i++)
        ri[i]=0;
    for(i=1;i<=nt;i++)
        ri[s[i].col]++;
    sl[0]=1;
    for(int i=1;i<=col;i++){
        sl[i]=sl[i-1]+ri[i-1];
    }
    for(int i=1;i<=col;i++){
        j=sl[s[i].col]++;
        t[j].col=s[i].row;
        t[j].row=s[i].col;
        t[j].val=s[i].val;
    }
}

int main()
{
    smt s[MAX],t[MAX];
    cout<<"Enter the number of rows and columns in the matrix: ";
    int r,c;
    cin>>r>>c;
    cout<<"Enter "<<r*c<<" elements:\n";
    int value,k=1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>value;
            if(value!=0){
                s[k++].createSm(i,j,value);
            }
        }
    }
    s[0].createSm(r,c,k-1);
    s[0].fastTranspose(s,t);
    cout<<"The transpose of the given matrix is:\n";
    k=1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(t[k].row==i && t[k].col==j){
                cout<<t[k].val<<" ";
                k++;
            }
            else
                cout<<"0 ";
        }
        cout<<"\n";
    }
}
