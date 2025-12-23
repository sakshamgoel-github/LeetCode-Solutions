#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    int maxi;
public:
    Solution(){maxi=0;}
    int solve(int ind, int mask, vector<int>&nums){
        if(ind == nums.size()){
            return (mask == maxi);
        }
        int take = solve(ind+1, mask | nums[ind], nums);
        int not_take = solve(ind+1, mask, nums);

        return (take+not_take);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        for(int &x: nums){
            maxi |= x;
        }
        return solve(0, 0, nums);
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