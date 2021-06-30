#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph(100000);
vector<bool> visited(100000, false);

int maxDis = INT32_MIN;
int maxNode;

void dfs(int start, int dis)
{
    visited[start] = true;
    if (dis > maxDis)
    {
        maxDis = dis;
        maxNode = start;
    }
    for (int child : graph[start])
    {
        if (!visited[child])
        {
            dfs(child, dis + 1);
        }
    }
}

int main()
{

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a;
        int b;
        cin >> a;
        cin >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);
    maxDis = INT32_MIN;
    fill(visited.begin(), visited.end(), false);
    dfs(maxNode, 0);

    cout << maxDis << endl;
}