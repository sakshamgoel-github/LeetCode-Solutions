#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    vector<vector<int>> child =
        {
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int n;

public:
    bool checkValid(int i, int j, vector<vector<int>>&grid)
    {
        if (i < 0)
            return false;
        if (i >= n)
            return false;
        if (j < 0)
            return false;
        if (j >= n)
            return false;
        if (grid[i][j])
            return false;
        return true;
    }

    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        this->n = grid.size();
        if (grid[0][0] || grid[n - 1][n - 1])
            return -1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        int ans = 1;
        while (!q.empty())
        {
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                auto curr = q.front();
                q.pop();
                if (curr.first == n - 1 && curr.second == n - 1)
                    return ans;
                for (auto x : child)
                {
                    if (checkValid(curr.first + x[0], curr.second + x[1],grid))
                    {
                        q.push({curr.first + x[0], curr.second + x[1]});
                        grid[curr.first+x[0]][curr.second+x[1]] = 1;
                    }
                }
            }
            ++ans;
        }
        return -1;
    }
};

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    vector<vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    Solution obj;
    cout << obj.shortestPathBinaryMatrix(grid);
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}