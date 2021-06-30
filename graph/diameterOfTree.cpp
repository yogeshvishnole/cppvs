#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph(1000);
vector<bool> visited(1000);
// vector<int> dis(1000);
int maxDis = INT32_MIN;
int maxNode;

void dfs(int i, int dist)
{
    visited[i] = true;
    // dis[i] = dist;
    if (dist > maxDis)
    {
        maxDis = dist;
        maxNode = i;
    }
    for (int child : graph[i])
    {
        if (!visited[child])
        {
            dfs(child, dist + 1);
        }
    }
}

int main()
{
    int v;
    // int e;
    cin >> v;
    for (int i = 0; i < v - 1; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0);
    maxDis = 0;
    fill(visited.begin(), visited.end(), false);
    dfs(maxNode, 0);
    cout << maxDis << endl;
}