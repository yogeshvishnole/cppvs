#include <iostream>
#include <vector>
using namespace std;

bool isCycle(int start, vector<vector<int>> &graph, vector<bool> &visited, int parent)
{
    visited[start] = true;
    for (int child : graph[start])
    {
        if (!visited[child])
        {
            if (isCycle(child, graph, visited, start) == true)
                return true;
        }
        else if (child != parent)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int v;
    int e;
    cin >> v >> e;
    vector<vector<int>> graph(v + 1);
    vector<bool> visited(v + 1, false);

    for (int i = 0; i < e; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bool ans = isCycle(1, graph, visited, 1);
    cout << boolalpha << ans << endl;
}