#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int>rows(m);
        vector<int>cols(n);
        
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(mat[i][j] == 1){
                    rows[i]++;
                    cols[j]++;
                }
            }
        }    
        int ans = 0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1) ++ans;
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