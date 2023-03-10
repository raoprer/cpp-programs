#include <iostream>
using namespace std;

void component(int a[][20],int visited[20],int n,int s)
{
    int q[20],f=-1,r=-1;
    q[++r]=s;
    visited[s]=1;
    while(f<r){
        int u=q[++f];
        for(int v=1;v<=n;v++){
            if(a[u][v]==1 && !visited[v]){
                q[++r]=v;
                visited[v]=1;
            }
        }
        cout<<u<<" ";
    }

    cout<<endl;

    for(int i=1;i<=n;i++){
        if(visited[i]==0)
            component(a,visited,n,i);
    }
}

int main()
{
    int a[20][20];
    a[1][2]=1;
    a[2][3]=1;
    a[2][4]=1;
    a[5][6]=1;
    a[9][8]=1;
    a[8][7]=1;
    int visited[20]={0};
    component(a,visited,9,1);
}
