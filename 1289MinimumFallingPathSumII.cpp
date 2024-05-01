#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    vector<vector<int>>t;
public:
    int solve(int row, int prev, vector<vector<int>>& grid){
        if(row == grid.size())
            return 0;
        if(prev != -1 && t[row][prev] != -1)
            return t[row][prev];
        int ans = 1e5;
        for(int i=0;i<grid.size();++i){
            if(i == prev)
                continue;
            int t = solve(row+1, i, grid) + grid[row][i];
            ans = min(ans, t);
        }
        if(prev != -1)
        return t[row][prev] = ans;
        return ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        t.resize(n,vector<int>(n,-1));
        return solve(0,-1,grid);
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