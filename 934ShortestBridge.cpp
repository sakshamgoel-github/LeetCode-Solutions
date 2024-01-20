#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    vector<vector<bool>> vis;
    vector<vector<int>> graph;
    queue<pair<int, int>> q;
    int n;

public:
    void dfs(int i, int j)
    {
        if (i < 0 || j < 0 || i >= n || j >= n)
            return;
        if (!graph[i][j])
            return;
        if (vis[i][j])
            return;
        vis[i][j] = true;
        q.push({i, j});  
        dfs(i + 1, j);
        dfs(i - 1, j);
        dfs(i, j + 1);
        dfs(i, j - 1);
    }
    int shortestBridge(vector<vector<int>> &grid)
    {
        graph = grid;
        this->n = graph.size();
        vis.resize(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
        {
            bool flag = false;
            for (int j = 0; j < n; j++)
            {
                if (graph[i][j])
                {
                    dfs(i, j);
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
        int level = 0;
        while (!q.empty())
        {
            int size = q.size();
            for (int k = 0; k < size; k++)
            {

                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                if ((i + 1 < n) && !vis[i + 1][j])
                {
                    if (graph[i + 1][j])
                        return level;
                    else
                    {
                        q.push({i + 1, j});
                        vis[i + 1][j] = true;
                    }
                }
                if ((i - 1 >= 0) && !vis[i - 1][j])
                {
                    if (graph[i - 1][j])
                        return level;
                    else
                    {
                        q.push({i - 1, j});
                        vis[i - 1][j] = true;
                    }
                }
                if ((j + 1 < n) && !vis[i][j + 1])
                {
                    if (graph[i][j + 1])
                        return level;
                    else
                    {
                        q.push({i, j + 1});
                        vis[i][j + 1] = true;
                    }
                }
                if ((j - 1 >=0 ) && !vis[i][j - 1])
                {
                    if (graph[i][j - 1])
                        return level;
                    else
                    {
                        q.push({i, j - 1});
                        vis[i][j - 1] = true;
                    }
                }
            }
            ++level;
        }
        return level;
    }
};

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}