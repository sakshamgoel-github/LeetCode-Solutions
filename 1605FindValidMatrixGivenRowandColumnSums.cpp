#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(); int m = colSum.size();
        vector<vector<int>>v(n,vector<int>(m));
        int i=0,j=0;
        while(i<n && j<m){
            if(rowSum[i] < colSum[j]){
                v[i][j] = rowSum[i];
                colSum[j] -= rowSum[i];
                ++i;
            }
            else{
                v[i][j] = colSum[j];
                rowSum[i] -= colSum[j];
                ++j;
            }
        }
        return v;
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
