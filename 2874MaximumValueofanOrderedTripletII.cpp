#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long ans = 0;
            int n = nums.size(), leftMax = nums[0];
            vector<int>rightMax(n-1);
            rightMax[n-2]=nums[n-1];
            for(int i=n-3;i>=0;--i){
                rightMax[i] = max(rightMax[i+1],nums[i+1]);
            }
            for(int i=1;i<n-1;++i){
                long long temp = (leftMax - nums[i])*1LL*rightMax[i];
                ans = (ans > temp) ? ans : temp;
                leftMax = (leftMax > nums[i]) ? leftMax : nums[i];
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