#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    int rows, cols;
    bool isValid(int i, int j, int rob, vector<vector<bool>> vis0, vector<vector<bool>> vis1) //[params: cell row, cell col, robot number]
    {
        if (i < 0 || i >= rows || j < 0 || j >= cols)
            return false;
        if (rob)
        {
            if (vis1[i][j])
                return false;
        }
        else
        {
            if (vis0[i][j])
                return false;
        }
        return true;
    }
    int solve(int i, int j, int k, int l, vector<vector<int>> &grid, vector<vector<bool>> vis0, vector<vector<bool>> vis1)
    {
        if (!isValid(i, j, 0,vis0,vis1) || !isValid(k, l, 1,vis0,vis1))
            return 0;

        int amt0 = grid[i][j];
        // grid value should become 0 after visiting it
        grid[i][j] = 0;

        int amt1 = grid[k][l];
        // grid value should become 0 after visiting it
        grid[k][l] = 0;

        vis0[i][j] = true;
        vis1[k][l] = true;

        int maxi = 0;
        // exploring all the 9 possibilities
        for (int x = -1; x <= 1; x++)
        {
            for (int y = -1; y <= 1; y++)
            {
                maxi = max(maxi, solve(i + 1, j + x, k + 1, l + y, grid,vis0,vis1));
            }
        }

        // restoring the grid value as we are passing it by reference
        grid[i][j] = amt0;
        grid[k][l] = amt1;
        vis0[i][j] = false;
        vis1[k][l] = false;
        return (maxi + amt0 + amt1);
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        vector<vector<bool>> vis0;
        vector<vector<bool>> vis1;
        rows = grid.size();
        cols = grid[0].size();

        vis0.resize(rows, vector<bool>(cols, false)); // visited for robot 0
        vis1.resize(rows, vector<bool>(cols, false)); // visited for robot 1

        return solve(0, 0, 0, cols - 1, grid, vis0, vis1);
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