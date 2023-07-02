#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
private:
    int n, m;
    vector<vector<bool>> vis;
    vector<vector<int>> grid;

    bool dfs(int i, int j)
    {
        if (i >= n || j >= m || i < 0 || j < 0)
            return false;
        else if (grid[i][j]) // checking if current node is water
            return false;
        else if (vis[i][j])
            return false;

        vis[i][j] = true;

        bool ans = false;
        bool ans1 = dfs(i + 1, j);
        bool ans2 = dfs(i - 1, j);
        bool ans3 = dfs(i, j + 1);
        bool ans4 = dfs(i, j - 1);

        if (i == 0 || i == (n - 1) || j == 0 || j == (m - 1))
            ans = true;

        ans = ans | ans1 | ans2 | ans3 | ans4;
        return ans;
    }

public:
    int closedIsland(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        this->grid = grid;
        vis.resize(n);
        for (int i = 0; i < n; i++)
        {
            vis[i].resize(m);
        }

        int cc = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && !grid[i][j])
                {
                    ++cc;
                    cc = cc - dfs(i, j);
                }
            }
        }
        if (cc < 0)
            return 0;
        return cc;
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