#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph(100000);
vector<bool> visited(100000);
vector<int> sssp(100000);
vector<int> fourDigitPrimes;

bool isPrime(int n)
{
    for (int i = 2; (i * i) <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool isValid(int a, int b)
{
    int cnt = 0;
    while (a > 0)
    {
        if (a % 10 != b % 10)
            cnt++;
        a = a / 10;
        b = b / 10;
    }
    if (cnt == 1)
        return true;
    else
        return false;
}

void buildFourDigitPrimes()
{
    for (int i = 1000; i <= 9999; i++)
    {
        if (isPrime(i))
        {
            fourDigitPrimes.push_back(i);
        }
    }
}

void buildGraph()
{
    buildFourDigitPrimes();
    for (int i = 0; i < fourDigitPrimes.size(); i++)
    {
        int a = fourDigitPrimes[i];
        for (int j = i + 1; j < fourDigitPrimes.size(); j++)
        {
            int b = fourDigitPrimes[j];
            if (isValid(a, b))
            {
                graph[a].push_back(b);
                graph[b].push_back(a);
            }
        }
    }
}

void bfs(int node)
{
    queue<int> q;
    q.push(node);
    sssp[node] = 0;
    visited[node] = true;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int child : graph[curr])
        {
            if (!visited[child])
            {
                visited[child] = true;
                sssp[child] = sssp[curr] + 1;
                q.push(child);
            }
        }
    }
}

int main()
{

    int t, a, b;
    buildGraph();
    cin >> t;
    while (t--)
    {
        for (int i = 1000; i <= 9999; i++)
        {
            visited[i] = false;
            sssp[i] = -1;
        }

        cin >> a >> b;
        bfs(a);
        if (sssp[b] == -1)
        {
            cout << "Impossible" << endl;
        }
        else
        {
            cout << sssp[b] << endl;
        }
    }
}
