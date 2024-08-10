#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    int m,n;
    vector<vector<int>>t;
public:
    int solve(int i, int j,vector<vector<int>>& obstacleGrid){
        if ( i<0 || j<0 || i>=m || j>=n)
        return 0;
        
        if(obstacleGrid[i][j])
        return 0;

        if( i == (m-1) && j == (n-1))
        return 1;


        if(t[i][j]!=-1)
        return t[i][j];

        int choice1 = solve(i+1,j,obstacleGrid);
        int choice2 = solve(i,j+1,obstacleGrid);

        return t[i][j] = (choice1 + choice2);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        t.resize(m+1,vector<int>(n+1,-1));
        return solve(0,0,obstacleGrid);
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