#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n < 5)
            return 0;
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        int t1 = nums[n-1] - nums[3];
        int t2 = nums[n-2] - nums[2];
        int t3 = nums[n-3] - nums[1];
        int t4 = nums[n-4] - nums[0];
        ans = min({ans,t1,t2,t3,t4});
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