#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        unordered_set<int>s;
        int n=nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i=1;i<n;++i){
            if(nums[i] <= nums[i-1]){
                ans += nums[i-1] - nums[i] + 1;
                nums[i] = nums[i-1]+1;
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