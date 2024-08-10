#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int pre = 1, suff = 1;
        for(int i=0;i<n;++i){
            if(pre == 0) pre = 1;
            if(suff == 0) suff = 1;
            pre = pre * nums[i];
            suff = suff * nums[n - i - 1];
            maxi = max({pre,suff,maxi});
        }    
        return maxi;
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