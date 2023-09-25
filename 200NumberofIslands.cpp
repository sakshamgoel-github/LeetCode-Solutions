#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    int n, m;

public:
    bool isValid(int i, int j)
    {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    }
    void bfs(int i, int j, vector<vector<char>> &grid)
    {
        if (!isValid(i, j))
            return;
        if (grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        bfs(i + 1, j, grid);
        bfs(i - 1, j, grid);
        bfs(i, j + 1, grid);
        bfs(i, j - 1, grid);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1'){
                    ++cnt;
                    bfs(i,j,grid);
                }
            }
        }
        return cnt;
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