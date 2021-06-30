#include <iostream>
using namespace std;

char arr[10001][10001];
int vis[10001][10001];
int N, M;
int cc;

bool isValid(int x, int y)
{
    if (x < 1 || x > N || y < 1 || y > M)
    {
        return false;
    }
    if (vis[x][y] == 1)
    {
        return false;
    }
    if (arr[x][y] == '#')
    {
        return false;
    }
    return true;
}

void dfs(int x, int y)
{
    vis[x][y] = 1;
    if (isValid(x + 1, y))
    {
        dfs(x + 1, y);
    }

    if (isValid(x, y + 1))
    {
        dfs(x, y + 1);
    }

    if (isValid(x - 1, y))
    {
        dfs(x - 1, y);
    }

    if (isValid(x, y - 1))
    {
        dfs(x, y - 1);
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> arr[i][j];

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (arr[i][j] == '.' && vis[i][j] == 0)
            {
                dfs(i, j);
                cc++;
            }
        }
    }

    cout << cc << endl;
}
