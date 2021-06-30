#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph(100000);
vector<int> res;
int in[100000];

bool kahn(int v)
{
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= v; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int curr = q.top();
        res.push_back(curr);
        q.pop();
        for (int child : graph[curr])
        {
            in[child]--;
            if (in[child] == 0)
            {
                q.push(child);
            }
        }
    }
    return res.size() == v;
}

int main()
{
    int v, e;
    cin >> v >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        in[b]++;
    }
    bool isTopo = kahn(v);
    if (isTopo)
    {
        for (int i : res)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Sandro fails." << endl;
    }
}
