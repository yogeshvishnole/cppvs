#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> graph(100000);
vector<bool> visited(100000);
vector<int> sssp(100000);

void bfs(int node){
    queue<int> q;
    q.push(node);
    visited[node] =true;
    sssp[node] = 0;
    while(!q.empty()){
        int a = q.front();
        cout<<a<<" ";
        q.pop();
        for(int child:graph[a]){
            if(!visited[child]){
                visited[child] = true;
                sssp[child] = sssp[a] + 1;
                q.push(child);
            }
        }
    }
}

int main(){
    int v;
    int e;
    cin>>v>>e;
    for(int i = 0;i<e;i++){
        int a;
        int b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs(3);
    cout<<endl;
    for(int i = 1;i<=v;i++){
        cout<<i<<" "<<sssp[i]<<endl;
    }
}
