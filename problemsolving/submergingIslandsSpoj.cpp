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

void dfs(int node, int parent)
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
            low[node] = min(low[node], in[ot]);
        }
        if (!visited[ot])
        {
            dfs(ot, node);
            if (low[ot] >= in[node] && parent != -1)
            {
                AP.insert(node);
            }
            low[node] = min(low[ot], low[node]);
            children++;
        }
    }
    if (parent == -1 && children > 1)
    {
        AP.insert(node);
    }
}

int main()
{
    int v, e, a, b;

    while (1)
    {
        cin >> v >> e;
        if (v == 0 && e == 0)
            break;
        for (int i = 0; i <= v; i++)
        {
            visited[i] = false;
            graph[i].clear();
        }
        AP.clear();
        timer = 1;
        while (e--)
        {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for (int i = 1; i <= v; i++)
        {
            if (!visited[i])
            {
                dfs(i, -1);
            }
        }

        cout << AP.size() << endl;
    }
}