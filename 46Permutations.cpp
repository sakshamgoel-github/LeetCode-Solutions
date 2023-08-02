#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    int N;
    vector<vector<int>>ans;
public:
void solve(int i, vector<int>&nums){
    if(i==N){
        ans.push_back(nums);
    }
    else{
        for (int j = i; j < N; j++)
        {
            swap(nums[i],nums[j]);
            solve(i+1,nums);
            swap(nums[i],nums[j]);
        }        
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        N = nums.size();
        solve(0,nums);
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