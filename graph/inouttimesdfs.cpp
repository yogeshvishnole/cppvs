#include <iostream>
#include <vector>
using namespace std;

void calculateInOutTimes(int start, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &in, vector<int> &out, int &timer)
{
    visited[start] = true;
    in[start] = timer++;
    for (int child : graph[start])
    {
        if (!visited[child])
        {
            calculateInOutTimes(child, graph, visited, in, out, timer);
        }
    }
    out[start] = timer++;
}

int main()
{

    int v;
    int e;
    cin >> v >> e;
    vector<vector<int>> graph(v + 1);
    vector<bool> visited(v + 1);
    vector<int> in(v + 1);
    vector<int> out(v + 1);
    int timer = 1;

    for (int i = 0; i < e; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    calculateInOutTimes(1, graph, visited, in, out, timer);
    cout << "In times : " << endl;
    for (int i : in)
    {
        cout << i << " ";
    }
    cout << "Out times : " << endl;
    for (int i : out)
    {
        cout << i << " ";
    }
    cout << endl;
}