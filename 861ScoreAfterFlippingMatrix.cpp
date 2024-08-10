#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int ans = 0;
        ans += pow(2,cols-1)*rows;
        for (int j = 1; j < cols; j++)
        {
            int ones = 0;
            for (int i = 0; i < rows; i++)
            {
                if(grid[i][0] == grid[i][j])
                    ++ones;
            }
            int zeroes = rows - ones;
            if(zeroes > ones)
                ones = zeroes;
            ans += pow(2, cols - j - 1)*ones;
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