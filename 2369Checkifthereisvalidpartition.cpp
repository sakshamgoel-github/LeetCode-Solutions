#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    int n;
    vector<int> t;

public:
    bool solve(int i, vector<int> &nums)
    {
        if (i >= n)
            return true;
        if (t[i] != -1)
            return t[i];
        bool ans = false;
        if ((i < n - 1) && (nums[i] == nums[i + 1]))
            ans = solve(i + 2, nums);
        if (ans)
            return t[i] = ans;
        if (i < n - 2)
        {
            if (nums[i] == nums[i + 1] && nums[i] == nums[i + 2])
                ans = solve(i + 3, nums);
            if (ans)
                return t[i] = ans;
            if ((nums[i] + 1) == nums[i + 1] && (nums[i + 1] + 1) == nums[i + 2])
                ans = solve(i + 3, nums);
        }
        return t[i] = ans;
    }
    bool validPartition(vector<int> &nums)
    {
        n = nums.size();
        t.resize(n + 1, -1);
        return solve(0, nums);
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