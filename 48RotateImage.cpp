#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0;i<n;++i){
            reverse(matrix[i].begin(),matrix[i].end());
        }
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