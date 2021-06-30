#include <iostream>
#include <vector>
using namespace std;
#define mod 1000000007

void dfs(int start, vector<vector<int>> &graph, vector<bool> &visited, int &numCounts)
{

    visited[start] = true;
    numCounts++;

    for (int child : graph[start])
    {
        if (!visited[child])
        {
            dfs(child, graph, visited, numCounts);
        }
    }
}

int main()
{

    int t;
    cin >> t;

    while (t--)
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

        int cc = 0;
        int ew = 1;
        for (int i = 1; i <= v; i++)
        {
            if (!visited[i])
            {
                cc++;
                int numCounts = 0;
                dfs(i, graph, visited, numCounts);
                ew *= numCounts % mod;
            }
        }
        cout << cc << " " << (ew % mod) << endl;
    }

    return 0;
}
