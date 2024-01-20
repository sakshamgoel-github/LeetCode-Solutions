#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int plus = 0, neg = 1;
        for(int i = 0;i<n;++i){
            if(nums[i] > 0){
                ans[plus] = nums[i];
                plus+=2;
            }
            else {
                ans[neg] = nums[i];
                neg+=2;
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