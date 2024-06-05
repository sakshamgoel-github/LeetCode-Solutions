#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    int ans;
    bool isValid(int num, int k, vector<int>&v){
        int n = v.size();
        for(int i=0;i<n;++i){
            if(abs(v[i] - num) == k)
                return false;
        }
        return true;
    }
    void solve(int ind, vector<int>&curr,vector<int>& nums, int k){
        if(ind == nums.size()){
            if(curr.size())
                ++ans;
        }
        else{
            if(isValid(nums[ind], k, curr)){
                curr.push_back(nums[ind]);
                solve(ind+1, curr, nums, k);
                curr.pop_back();
            }
            solve(ind+1, curr, nums, k);
        }
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int>curr;
        solve(0, curr, nums, k);
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