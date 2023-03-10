#include <iostream>
using namespace std;

void bfs(int a[][10],int n,int s)
{
    int vis[n+1],u,v;
    for(int i=1;i<=n;i++)
        vis[i]=0;
    int q[n],f=-1,r=-1;
    q[++r]=s;
    vis[s]=1;
    while(f<r){
        u=q[++Sf];
        for(v=1;v<=n;v++){
            if(a[u][v]==1 && vis[v]!=1){
                q[++r]=v;
                vis[v]=1;
            }
        }
        cout<<u<<" ";
    }
}

int main()
{
    cout<<"Enter the number of vertices and edges: ";
    int n,e;
    cin>>n>>e;
    int a[10][10];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            a[i][j]=0;
    }
    int p,q;
    for(int i=1;i<=e;i++){
        cout<<"Enter edge "<<i<<": ";
        cin>>p>>q;
        a[p][q]=1;
    }
    cout<<endl;
    cout<<"Enter the source: ";
    int s;
    cin>>s;
    bfs(a,n,s);
}
