// #include <iostream>
// #include <vector>
// #include <string>
// #include <limits>
// using namespace std;

// vector<string> tokenize(string s, string del = " ")
// {
//     vector<string> v;
//     int start = 0;
//     int end = s.find(del);
//     while (end != -1)
//     {
//         v.push_back(s.substr(start, end - start));
//         start = end + del.size();
//         end = s.find(del, start);
//     }
//     v.push_back(s.substr(start, end - start));
//     return v;
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         int m;
//         cin >> n >> m;
//         vector<vector<int>> equals(n + 1);
//         vector<vector<int>> notequals(n + 1);
//         for (int i = 0; i <= n; i++)
//         {
//             for (int j = 0; j <= n; j++)
//             {
//                 equals[i].push_back(0);
//                 notequals[i]
//                     .push_back(0);
//             }
//         }
//         cin.ignore(numeric_limits<streamsize>::max(), '\n');
//         for (int i = 0; i < m; i++)
//         {
//             string str;

//             getline(cin, str);
//             vector<string>
//                 equ = tokenize(str);
//             if (equ[1] == "=")
//             {
//                 equals[atoi(equ[0].c_str())][atoi(equ[2].c_str())] = 1;
//             }
//             else
//             {
//                 notequals[atoi(equ[0].c_str())][atoi(equ[2].c_str())] = 1;
//             }
//         }

//         int i;
//         for (i = 0; i <= n; i++)
//         {
//             int j;
//             for (j = 0; j <= n; j++)
//             {
//                 if (equals[i][j] == 1 && notequals[i][j] == 1)
//                 {
//                     cout << "NO" << endl;
//                     break;
//                 }
//             }
//             if (j <= n)
//             {
//                 break;
//             }
//         }
//         if (i <= n)
//         {
//             continue;
//         }
//         cout << "YES" << endl;
//     }
// }

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<vector<int>> graph(100000);
vector<bool> visited(100000, false);
vector<int> cc(100000);
int curr_cc = 0;

void dfs(int node)
{
    visited[node] = true;
    cc[node] = curr_cc;
    for (int child : graph[node])
    {
        if (!visited[child])
        {
            dfs(child);
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        curr_cc = 0;
        for (int i = 0; i < 100000; i++)
            graph[i]
                .clear(),
                visited[i] = false;
        cin >> n >> m;
        vector<pair<int, int>> edgelist;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            string op;
            cin >> a >> op >> b;
            if (op == "=")
            {
                graph[a].push_back(b);
                graph[b].push_back(a);
            }
            else
            {
                edgelist.push_back({a, b});
            }
        }

        for (int i = 1; i <= n; i++)
        {
            curr_cc++;
            if (!visited[i])
            {
                dfs(i);
            }
        }

        bool flag = true;

        for (int i = 0; i < edgelist.size(); i++)
        {
            if (cc[edgelist[i].first] == cc[edgelist[i].second])
            {
                flag = false;
                break;
            }
        }
        if (!flag)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}
