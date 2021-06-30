#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int n, m;
int dis[501][501];
int vis[501][501];
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool isValid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
    {
        return false;
    }
    if (vis[x][y] == 1)
        return false;
    return true;
}

void bfs(int sx, int sy)
{

    queue<pair<int, int>> q;
    q.push({sx, sy});
    vis[sx][sy] = 1;
    dis[sx][sy] = 0;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int curx = x + dx[i];
            int cury = y + dy[i];
            if (isValid(curx, cury) && vis[curx][cury] == 0)
            {
                vis[curx][cury] = 1;
                dis[curx][cury] = dis[x][y] + 1;
                q.push({curx, cury});
            }
        }
    }
}

int main()
{
    int sx, sy, destx, desty;
    cin >> n >> m >> sx >> sy >> destx >> desty;
    if (sx == destx && sy == desty)
        cout << 0 << endl;
    else
    {
        bfs(sx, sy);
        if (dis[destx][desty])
            cout << dis[destx][desty] << endl;
        else
        {
            cout << -1 << endl;
        }
    }
}