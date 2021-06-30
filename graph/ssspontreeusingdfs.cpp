#include <iostream>
#include <vector>
using namespace std;

void dfs(int start, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &dis, int sd)
{
    visited[start] = true;
    dis[start] = sd;
    for (int child : graph[start])
    {
        if (!visited[child])
        {
            dfs(child, graph, visited, dis, dis[start] + 1);
        }
    }
}

int main()
{
    int v;
    int e;
    int source;
    cin >> v >> e >> source;
    vector<vector<int>> graph(v + 1);

    for (int i = 0; i < e; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(v + 1);
    vector<int> dis(v + 1);

    dfs(source, graph, visited, dis, 0);

    for (int i = 0; i < dis.size(); i++)
    {
        cout << dis[i] << " ";
    }

    cout << endl;
}