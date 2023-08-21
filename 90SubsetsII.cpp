#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    int n;
    vector<vector<int>> ans;

public:
    void solve(int i, vector<int> &t, vector<int> &nums)
    {
        ans.push_back(t);
        if (i >= n)
        {
        }
        while (i < n)
        {   
            t.push_back(nums[i]);
            solve(i + 1, t, nums);
            t.pop_back();
            while (i < (n - 1) && nums[i] == nums[i + 1])
            {
                ++i;
            }
            ++i;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> t;
        solve(0, t, nums);
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