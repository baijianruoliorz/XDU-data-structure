#include<iostream>
#include<cstring>

using namespace std;

int graph[1005][1005];
bool visited[1005];
int vexnum;

int firstneighbor(int begin){
    for(int i=1;i<=vexnum;i++){
        if(graph[begin][i]==1){
            return i;
        }
    }
    return -1;
}

int nextneighbor(int begin,int nownode){
    for(int i=begin+1;i<=vexnum;i++){
        if(graph[nownode][i]==1){
            return i;
        }
    }
    return -1;
}

void Dfs(int v){
    cout<<v<<" ";
    visited[v]=true;
    for(int i=firstneighbor(v);i>0;i=nextneighbor(i,v)){
       if(!visited[i]){
           Dfs(i);
       }
    }
}

int DfsTraverse(){
    for(int i=1;i<=vexnum;i++){
       visited[i]=false;
    }
    int count=0;
    for(int i=1;i<=vexnum;i++){
        if(!visited[i]){
           Dfs(i);
           count++;
        }
    }
    return count;
}

int main(){
    cin>>vexnum;
    for(int i=1;i<=vexnum;i++){
        for(int j=1;j<=vexnum;j++){
            cin>>graph[i][j];
        }
    }
    int ans;
    ans=DfsTraverse();
    cout<<endl;
    cout<<ans<<endl;
    return 0;
}
