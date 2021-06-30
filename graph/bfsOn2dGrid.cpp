#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int dis[10000][10000];
int vis[10000][10000];
int N, M;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

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
    return true;
}

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    vis[x][y] = 1;
    dis[x][y] = 0;
    q.push({x, y});
    while (!q.empty())
    {
        int curr_x = q.front().first;
        int curr_y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (isValid(curr_x + dx[i], curr_y + dy[i]))
            {
                vis[curr_x + dx[i]][curr_y + dy[i]] = 1;
                dis[curr_x + dx[i]][curr_y + dy[i]] = dis[curr_x][curr_y] + 1;
                q.push({curr_x + dx[i], curr_y + dy[i]});
            }
        }
    }
    cout << "Distance array" << endl;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int x, y;
    cin >> N >> M;
    cin >> x >> y;
    bfs(x, y);
}