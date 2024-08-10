#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int minMax = 1e5+1;
        for(int j=0;j<m;++j){
            int maxi = 0;
            for(int i=0;i<n;++i){
                maxi = max(maxi,matrix[i][j]);
            }
            minMax = min(minMax,maxi);
        }    
        int maxMin = 0;
        for(int i=0;i<n;++i){
            int mini=1e5+1;
            for(int j=0;j<m;++j){
                mini = min(mini,matrix[i][j]);
            }
            maxMin = max(maxMin,mini);
        }
        return (minMax == maxMin) ? vector<int>{minMax} : vector<int>{};
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