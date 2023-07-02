#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution {
private:
    int n, m;
    vector<vector<int>> grid;
    vector<vector<bool>> vis;

public:
    void dfs(int i, int j) {
        if (i >= n || j >= m || i < 0 || j < 0)
            return;
        else if (vis[i][j])
            return;
        else if (!grid[i][j])
            return;
        vis[i][j] = true;
        dfs(i + 1, j);
        dfs(i - 1, j);
        dfs(i, j + 1);
        dfs(i, j - 1);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        this->grid = grid;
        vis.resize(n, vector<bool>(m, false));

        // Mark all cells connected to the boundary as visited
        for (int i = 0; i < n; i++) {
            dfs(i, 0);
            dfs(i, m - 1);
        }
        for (int j = 0; j < m; j++) {
            dfs(0, j);
            dfs(n - 1, j);
        }

        int sizes = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j]) {
                    sizes += 1;
                }
            }
        }
        return sizes;
    }
};


int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    Solution obj;
    vector<vector<int>>grid = {
        {0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}
    };
    obj.numEnclaves(grid);
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}