#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph(1000000);
vector<int> in(1000000);
vector<int> low(1000000);
vector<bool> visited(1000000, false);
int timer;
int bridgeCount;

void dfs(int node, int parent)
{
    visited[node] = true;
    in[node] = low[node] = timer++;
    for (int child : graph[node])
    {
        if (child == parent)
            continue;
        if (visited[child])
        {
            // back edge
            low[node] = min(low[node], in[child]);
        }

        if (!visited[child])
        {
            // forward edge
            dfs(child, node);
            if (low[child] > in[node])
            {
                bridgeCount++;
            }
            low[node] = min(low[node], low[child]);
        }
    }
}
void printAns(int node, int parent)
{
    visited[node] = true;
    for (int child : graph[node])
    {
        if (child == parent)
            continue;
        if (visited[child])
        {
            if (in[node] > in[child])
            {
                cout << node << " " << child << endl;
            }
        }

        if (!visited[child])
        {
            cout << node << " " << child << endl;
            printAns(child, node);
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
    if (bridgeCount)
    {
        cout << 0 << endl;
    }
    else
    {
        for (int i = 0; i <= v; i++)
        {
            visited[i] = false;
        }
        printAns(1, -1);
    }
}