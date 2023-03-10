#include <iostream>
using namespace std;

int indegree(int a[][10],int p,int n)
{
    int c=0;
    for(int i=1;i<=n;i++)
        if(a[i][p]==1)
            c++;
    return c;
}

int main()
{
    cout<<"Enter the number of vertices and edges: ";
    int n,e;
    cin>>n>>e;
    int a[10][10];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            a[i][j]=0;
    int p,q;
    for(int i=1;i<=e;i++){
        cout<<"Enter edge "<<i<<" : ";
        cin>>p>>q;
        a[p][q]=1;
    }
    for(int p=1;p<=n;p++)
        cout<<"Indegree of "<<p<<" is: "<<indegree(a,p,n)<<endl;
}
