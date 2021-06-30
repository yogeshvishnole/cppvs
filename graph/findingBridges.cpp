#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph(100000);
vector<int> in(100000);
vector<int> low(100000);
vector<bool> visited(100000, false);
int timer;

void dfs(int node, int parent)
{
    visited[node] = true;
    in[node] = low[node] = timer++;
    for (int child : graph[node])
    {
        if (child == parent)
        {
            continue;
        }
        else if (visited[child])
        {

            // child is a back edge
            low[node] = min(low[node], in[child]);
        }
        else
        {
            // child forward edge
            dfs(child, node);
            if (low[child] > in[node])
            {
                cout << child << " -> " << node << " is a bridge" << endl;
            }
            low[node] = min(low[child], low[node]);
        }
    }
}

int main()
{
    int v;
    int e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, -1);
}
