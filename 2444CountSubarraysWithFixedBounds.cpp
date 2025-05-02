#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            int n = nums.size();
            int mini = -1, maxi = -1, cul = -1;
            long long ans = 0;
            for(int i=0;i<n;++i){
                if(nums[i] == minK)
                    mini = i;
                if(nums[i] == maxK)
                    maxi = i;
                else if(nums[i] < minK || nums[i] > maxK)
                    cul = i;
                int temp = min(mini, maxi) - cul;
                ans += 1LL*(temp > 0 ? temp : 0);
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