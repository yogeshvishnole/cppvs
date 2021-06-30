#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define pb push_back
#define vi vector<int>
#define vi2 vector<vector<int>>
#define REP(i, n) for (int i = 1; i <= n; i++)
using namespace std;

vi2 graph(1000);
vi2 tra(1000);
vi order;
vi sccc;
int vis[1000];

void dfs(int i)
{
    vis[i] = 1;
    for (int child : graph[i])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
    order.pb(i);
}

void dfs1(int i)
{
    vis[i] = 1;
    for (int child : tra[i])
    {
        if (!vis[child])
        {
            dfs1(child);
        }
    }
    sccc.pb(i);
}

int main()
{
    int n, m, a, b, t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        REP(i, n)
        graph.clear(),
            tra.clear(), order.clear(), sccc.clear(), vis[i] = 0;
        REP(i, m)
        cin >> a >> b,
            graph[a].pb(b), tra[b].pb(a);

        REP(i, n)
        if (vis[i] == 0)
        {
            dfs(i);
        }
        REP(i, n)
        vis[i] = 0;
        int scCount = 1;
        REP(i, n)
        if (vis[order[n - i]] == 0)
        {
            sccc.clear();
            dfs1(order[n - i]);
            cout << "Strongly component " << scCount << ":" << endl;
            for (int se : sccc)
            {
                cout << se << " ";
            }
            cout << endl;
            scCount++;
        }
    }
}
