// 2d grid can be assumed as a graph
// where cells are nodes and sides and corners can be assumed as edges
// in this dfs we only assume sides as edges
#include <iostream>
using namespace std;

int N, M;
int vis[1000001][1000001];

bool isValid(int x, int y)
{
    if (x < 1 || x > N || y > M || y < 1)
    {
        return false;
    }
    if (vis[x][y] == 1)
    {
        return false;
    }
    return true;
}

// dfs long way
void dfs(int x, int y)
{
    vis[x][y] = 1;
    if (isValid(x - 1, y))
    {
        dfs(x - 1, y);
    }
    if (isValid(x, y + 1))
    {
        dfs(x, y + 1);
    }
    if (isValid(x + 1, y))
    {
        dfs(x + 1, y);
    }
    if (isValid(x, y - 1))
    {
        dfs(x, y - 1);
    }
}

// dfs short way
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfsShort(int x,int y)
{
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        dfs(x + dx[i], y + dy[i]);
    }
}

int main()
{
}