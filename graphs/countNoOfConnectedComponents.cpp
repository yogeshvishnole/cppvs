#include <iostream>
#include <vector>
using namespace std;

void dfs(int i, vector<vector<int>> &graph, vector<bool> &visited)
{

    visited[i] = true;

    for (int child : graph[i])
    {
        if (!visited[child])
        {
            dfs(child, graph, visited);
        }
    }
}

int main()
{

    int v;
    int e;

    cin >> v;
    cin >> e;

    vector<vector<int>> graph(v + 1);
    vector<bool> visited(v + 1, false);

    for (int i = 0; i < e; i++)
    {
        int a;
        int b;

        cin >> a;
        cin >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int cc = 0;

    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            dfs(i, graph, visited);
            cc++;
        }
    }

    cout << "Count is : " << cc << endl;
    ;
}