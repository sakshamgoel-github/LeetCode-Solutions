#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    int m, n;

public:
    bool isValid(int i, int j)
    {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        m = mat.size();
        n = mat[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<vector<int>> ans(m, vector<int>(n, -1));

        queue<vector<int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!mat[i][j])
                {
                    q.push({i, j,0});
                    vis[i][j] = true;
                }
            }
        }
        while (!q.empty())
        {
            vector<int> curr = q.front();
            q.pop();
            int x = curr[0];
            int y = curr[1];
            int d = curr[2];
            ans[x][y] = d;

            if (isValid(x + 1, y) && !vis[x+1][y])
            {
                q.push({x + 1, y, d + 1});
                vis[x + 1][y] = true;
            }
            if (isValid(x - 1, y) && !vis[x-1][y])
            {
                q.push({x - 1, y, d + 1});
                vis[x - 1][y] = true;
            }
            if (isValid(x, y + 1) && !vis[x][y+1])
            {
                q.push({x, y + 1, d + 1});
                vis[x][y + 1] = true;
            }
            if (isValid(x, y - 1) && !vis[x][y-1])
            {
                q.push({x, y - 1, d + 1});
                vis[x][y - 1] = true;
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