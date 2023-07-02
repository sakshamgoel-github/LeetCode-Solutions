#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    int row, col;
public:
    bool dfs(int i, int j, vector<vector<int>> &grid)
    {
        if (i < 0 || i >= row || j < 0 || j >= col)
            return false;
        if (grid[i][j])
            return false;
        if (i == (row - 1))
            return true;

        grid[i][j] = 1;

        bool ans1 = dfs(i + 1, j, grid);
        bool ans2 = dfs(i - 1, j, grid);
        bool ans3 = dfs(i, j + 1, grid);
        bool ans4 = dfs(i, j - 1, grid);

        return ans1 | ans2 | ans3 | ans4;
    }
    bool solve(int mid,vector<vector<int>>&cells)
    {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        for (int i = 0; i < mid; i++)
        {
            int m = cells[i][0] - 1;
            int n = cells[i][1] - 1;

            grid[m][n] = 1;
        }
        for (int i = 0; i < col; i++)
        {
            if (dfs(0, i, grid))
            {
                return true;
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        this->row = row;
        this->col = col;
        int lo = 0, hi = cells.size() - 1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;

            if(solve(mid,cells))
            lo = mid + 1;
            else hi = mid - 1;
        }
        return hi;
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