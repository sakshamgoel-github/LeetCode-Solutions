#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int sum(int i, int j, int m, int n, vector<vector<int>>&grid,vector<vector<int>>&t){
        if(i==(m-1) && j==(n-1))
        return t[i][j] = grid[i][j];
        if(i>=m || j>=n)
        return INT16_MAX;
        if(t[i][j]!=-1)
        return t[i][j];
        int right, down;
        right = sum(i,j+1,m,n,grid,t);
        down = sum(i+1,j,m,n,grid,t);
        t[i][j] = min(right,down) + grid[i][j];
        return t[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>t(m + 1, vector<int>(n + 1, -1));
        return sum(0,0,m,n,grid,t);
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