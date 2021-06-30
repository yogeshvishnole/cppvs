#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> graph(100000);
vector<int> in(100000);
vector<int> low(100000);
vector<bool> visited(100000, false);
int timer;
set<int> AP;

int dfs(int node, int parent)
{
    visited[node] = true;
    in[node] = low[node] = timer++;
    int children = 0;
    for (int ot : graph[node])
    {
        if (ot == parent)
            continue;
        if (visited[ot])
        {
            // back edge
            low[node] = min(low[node], in[ot]);
        }
        if (!visited[ot])
        {
            dfs(ot, node);
            if (low[ot] >= in[node] && parent != -1)
            {
                AP.insert(node);
            }
            low[node] = min(low[node], low[ot]);
            children++;
        }
    }
    return children;
}

int main()
{
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int children = dfs(1, -1);
    if (children > 1)
    {
        AP.insert(1);
    }
    cout << "Artcount : " << AP.size() << endl;
}