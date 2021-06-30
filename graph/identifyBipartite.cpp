#include <iostream>
#include <vector>
using namespace std;

bool dfs(int start, vector<vector<int>> &graph, vector<bool> &visited, int color, vector<int> &colors)
{

    visited[start] = true;
    colors[start] = color;

    for (int child : graph[start])
    {

        if (!visited[child])
        {
            if (dfs(child, graph, visited, !color, colors) == false)
            {
                return false;
            }
        }
        else
        {
            if (colors[child] == colors[start])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{

    int v;
    int e;
    cin >> v >> e;
    vector<vector<int>> graph(v + 1);
    vector<bool> visited(v + 1);
    vector<int> colors(v + 1);

    for (int i = 0; i < e; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool isPartite = dfs(1, graph, visited, 0, colors);
    cout << boolalpha << "IsPartite : " << isPartite << endl;
}