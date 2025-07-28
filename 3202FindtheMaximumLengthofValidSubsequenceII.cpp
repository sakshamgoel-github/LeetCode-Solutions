#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>>t(k,vector<int>(n,1));
        int res = 1;
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                int m = (nums[i]+nums[j])%k;
                t[m][i] = max(t[m][i], t[m][j]+1);
                res = (res > t[m][i]) ? res : t[m][i];
            }
        }
        return res;
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