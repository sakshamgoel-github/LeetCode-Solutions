#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n/2;++i){
            int t = nums[i] + nums[n-i-1];
            ans = max(t,ans);
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