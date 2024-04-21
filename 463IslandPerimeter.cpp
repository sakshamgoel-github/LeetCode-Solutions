#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution  
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int perimeter = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    if (j - 1 < 0 || grid[i][j - 1] == 0)
                        ++perimeter;
                    if (j + 1 >= m || grid[i][j + 1] == 0)
                        ++perimeter;
                    if (i - 1 < 0 || grid[i - 1][j] == 0)
                        ++perimeter;
                    if (i + 1 >= n || grid[i + 1][j] == 0)
                        ++perimeter;
                }
            }
        }
        return perimeter;
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