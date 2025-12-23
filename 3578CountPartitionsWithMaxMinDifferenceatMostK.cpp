#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    int MOD = 1e9+7;
public:
    int solve(int index,vector<int>&t, int &k, vector<int>& nums){
        if(index >= nums.size()){
            return 1;
        }
        if(t[index] != -1){
            return t[index];
        }

        int ways = 0;
        int minEle = INT_MAX;
        int maxEle = INT_MIN;
        
        for (int j = index; j < nums.size(); j++)
        {
            minEle = min(minEle, nums[j]);
            maxEle = max(maxEle, nums[j]);

            if((maxEle - minEle) <= k){
                ways += solve(j+1, t, k, nums)%MOD;
            } else break;
        }
        
        return t[index] = ways;
    }
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>t(n+1,-1);
        return solve(0, t, k, nums);
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