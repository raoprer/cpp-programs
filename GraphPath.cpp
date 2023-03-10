#include<iostream>
using namespace std;

void pathGt3(int adjm[20][20], int n, int s){
    bool visited[20];
    for(int i=0; i<20; i++) visited[i]=false;
    int distance[20];
    int que[20];
    int f=-1;
    int e=-1;
    que[++e]=s;
    visited[s]=true;
    distance[s]=0;
    while(e!=f){
        int cv=que[++f];
        if(distance[cv]>=3){
            cout<<"path from "<<s<<" to "<<cv<<" greater than 3"<<endl;
        }
        for(int i=1; i<=n; i++){
            if(!visited[i] && adjm[cv][i]==1){
                visited[i]=true;
                distance[i]=distance[cv]+1;
                que[++e]=i;
            }
        }
    }
    cout<<endl;
}

int main(){
    int n=8;
    int adjmat[20][20];
    for(int i=1; i<=8; i++){
        for(int j=1; j<=8; j++){
            adjmat[i][j]=0;
        }
    }
    adjmat[1][2]=1;
    adjmat[2][3]=1;
    adjmat[3][4]=1;
    adjmat[4][5]=1;
    adjmat[5][6]=1;
    adjmat[6][7]=1;
    adjmat[7][8]=1;
    for(int i=1; i<=8; i++){
        pathGt3(adjmat, 8, i);
    }
}
