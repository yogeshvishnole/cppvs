#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph(100001);
vector<vector<int>> tra(100001);
vector<bool> vis(100001, false);
vector<int> order;
vector<int> sccc;
vector<int> res(100001, 0);

void dfs(int i)
{
    vis[i] = true;
    for (int child : graph[i])
    {
        if (vis[child] == false)
        {
            dfs(child);
        }
    }
    order.push_back(i);
}

void dfs1(int i)
{
    vis[i] = true;
    sccc.push_back(i);
    for (int child : tra[i])
    {
        if (vis[child] == false)
        {
            dfs1(child);
        }
    }
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        tra[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            dfs(i);
        }
    }
    fill(vis.begin(), vis.end(), false);
    reverse(order.begin(), order.end());
    for (int i = 1; i <= n; i++)
    {
        if (vis[order[i - 1]] == false)
        {
            sccc.clear();
            dfs1(order[i - 1]);
            if (sccc.size() == 1)
            {
                res[sccc[0]] = 0;
            }
            else if (sccc.size() > 1)
            {
                for (int se : sccc)
                {
                    res[se] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << " ";
    }
}
