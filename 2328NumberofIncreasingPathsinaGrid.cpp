#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    vector<vector<int>> t;
    int M, N;
    vector<vector<bool>> vis;
    long long MOD = 1e9+7;
public:
    bool isValid(int i, int j)
    {
        if (i < 0 || j < 0 || i >= M || j >= N)
            return false;
        return true;
    }

    int dfs(int i, int j, vector<vector<int>> &grid)
    {
        if (!isValid(i, j))
            return 0;
        else if (vis[i][j])
            return 0;

        vis[i][j] = true;
        int ways = 1;

        if (isValid(i - 1, j))
        {
            if ((grid[i - 1][j] > grid[i][j]))
            {
                if (t[i - 1][j] != -1)
                    ways += t[i - 1][j];
                else
                    ways += dfs(i - 1, j, grid);
            }
        }
        if (isValid(i + 1, j))
        {
            if ((grid[i + 1][j] > grid[i][j]))
            {
                if (t[i + 1][j] != -1)
                    ways += t[i + 1][j];
                else
                    ways += dfs(i + 1, j, grid);
            }
        }
        if (isValid(i, j + 1))
        {
            if ((grid[i][j + 1] > grid[i][j]))
            {
                if (t[i][j + 1] != -1)
                    ways += t[i][j + 1];
                else
                    ways += dfs(i, j + 1, grid);
            }
        }
        if (isValid(i, j - 1))
        {
            if ((grid[i][j - 1] > grid[i][j]))
            {
                if (t[i][j - 1] != -1)
                    ways += t[i][j - 1];
                else
                    ways += dfs(i, j - 1, grid);
            }
        }

        ways = ways % MOD;
        return t[i][j] = ways;
    }
    int countPaths(vector<vector<int>> &grid)
    {
        this->M = grid.size();
        this->N = grid[0].size();

        t.resize(M, vector<int>(N, -1));
        vis.resize(M, vector<bool>(N, false));

        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (!vis[i][j])
                    dfs(i, j, grid);
            }
        }

        long long int ans = 0;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; ++j)
            {
                ans = (ans + t[i][j])%MOD;
            }
        }

        return ans;
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