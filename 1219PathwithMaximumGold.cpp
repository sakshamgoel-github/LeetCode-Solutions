#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    int rows, cols;
public:
    int dfs(int i, int j, vector<vector<bool>>&vis,vector<vector<int>>&grid){
        if(i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == 0)
            return 0;
        if(vis[i][j])
            return 0;
        vis[i][j] = true;
        int maxi = 0;
        int up = dfs(i-1,j,vis,grid);
        int down = dfs(i+1,j,vis,grid);
        int left = dfs(i,j-1,vis,grid);
        int right = dfs(i,j+1,vis,grid);
        maxi = max({maxi,up,down,left,right});
        vis[i][j] = false;
        return maxi+grid[i][j];
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();    
        vector<vector<bool>>vis(rows, vector<bool>(cols, false));
        int ans = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int t = dfs(i,j,vis,grid);
                ans = max(ans, t);
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