#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph(1001);
vector<bool> visited(1001);
vector<int> dis(1001);

int main()
{
    int n,m;
    cin>>n>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}