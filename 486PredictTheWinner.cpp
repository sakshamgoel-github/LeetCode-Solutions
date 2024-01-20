#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    vector<vector<int>>t;
public:
    int solve(int i, int j, vector<int>&nums){
        if(i > j)
        return 0;
        if(i == j)
        return nums[i];
        if(t[i][j]!=-1)
        return t[i][j];
        int ans1 = nums[i] + min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        int ans2 = nums[j] + min(solve(i+1,j-1,nums),solve(i,j-2,nums));

        return t[i][j] = max(ans1,ans2);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int sum = 0;
        for(int &x:nums)
        sum += x;
        t.resize(21,vector<int>(21,-1));
        int p1 = solve(0,nums.size()-1,nums);
        int p2 = sum - p1;

        return p1 >= p2;
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