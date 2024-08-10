#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();      
        int n = grid[0].size();  

        vector<int>rows(m);    
        vector<int>cols(n);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1){
                    rows[i]++;
                    cols[j]++;
                }
            }
            
        }
        vector<vector<int>>diff(m);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {   
                int t = rows[i] + cols[j] - (n -rows[i]) - (m - cols[j]);
                diff[i].push_back(t);
            }            
        }
        return diff;            
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