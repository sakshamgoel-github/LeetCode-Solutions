#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    vector<vector<int>> t;

public:
    int solve(int ind, int target, vector<int> &nums)
    {
        if (!target)
            return 1;
        if (ind == nums.size() || target < 0)
            return 0;
        if (t[ind][target] != -1)
            return t[ind][target];
        int ans = 0, choice = 0;
        for (int i = ind; i < nums.size(); ++i)
        {
            int choice = solve(0, target - nums[i], nums);
            ans += choice;
        }
        return t[ind][target] = ans;
    }
    int combinationSum4(vector<int> &nums, int target)
    {
        t.resize(nums.size() + 1,vector<int>(target+1,-1));
        return solve(0, target, nums);
    }
};

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    Solution obj;
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}