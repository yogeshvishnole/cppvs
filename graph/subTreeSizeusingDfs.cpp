#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph(100000);
vector<bool> visited(100000);
vector<int> subTree(100000);

int dfs(int node)
{
    visited[node] = true;
    int curr_size = 1;
    for (int child : graph[node])
    {
        if (!visited[child])
        {
            curr_size += dfs(child);
        }
    }
    subTree[node] = curr_size;
    return curr_size;
}

int main()
{
    int v;
    cin >> v;
    for (int i = 0; i < v - 1; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    for (int i = 1; i <= v; i++)
    {
        cout << i << " " << subTree[i] << endl;
    }
}