#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#define pb push_back;
#define vi vector<int>
#define vi2 vector<vector<int>>
#define REP(i, n) for (int i = 1; i <= n; i++)
using namespace std;

int n, m;
pair<pair<int, int>, int> edges[100001];
int set[100001];
vector<pair<pair<int, int>, int>> spanTree;

int parent(int el)
{
    while (set[el] != el)
    {
        el = set[el];
    }
    return el;
}

void kruskals()
{
    for (int i = 1; i < n; i++)
    {
        set[i] = i;
    }
    int k = 0;
    int i = 0;
    while (k < n - 1)
    {
        int x = parent(edges[i].first.first);
        int y = parent(edges[i].first.second);
        i++;
        if (x == y)
        {
            continue;
        }
        k++;
        set[x] = y;
        spanTree.push_back(edges[i]);
    }
}

bool compare(pair<pair<int, int>, int> e1, pair<pair<int, int>, int> e2)
{
    return e1.second > e2.second;
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i].first.first = a;
        edges[i].first.second = b;
        edges[i].second = c;
    }
    sort(edges, edges + n, compare);
    cout << "sorted arr" << endl;
    for (int i = 0; i < m; i++)
    {
        cout << edges[i].first.first << " " << edges[i].first.second << " " << edges[i].second << endl;
    }
    kruskals();
    cout << "Ans" << endl;
    for (int i = 0; i < n - 1; i++)
    {
        cout << spanTree[i].first.first << " " << spanTree[i].first.second << " " << spanTree[i].second << endl;
    }
}