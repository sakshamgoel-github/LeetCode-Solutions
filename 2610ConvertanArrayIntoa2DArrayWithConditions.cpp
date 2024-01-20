#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> mp(n + 1, 0);
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            if (mp[nums[i]] >= ans.size()){
                ans.push_back({});
            }
            ans[mp[nums[i]]].push_back(nums[i]);
            mp[nums[i]]++;
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