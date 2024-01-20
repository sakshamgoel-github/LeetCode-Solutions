#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {   
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i = 0;
        vector<vector<int>> ans;
        while (i < n)
        {   
            int a = nums[i];
            int lo = i + 1, hi = n - 1;
            while (lo < hi)
            {
                if (!(nums[lo] + nums[hi] + nums[i]))
                {
                    ans.push_back({nums[i], nums[lo], nums[hi]});
                    while (lo < hi && nums[lo] == nums[lo + 1])
                    {
                        ++lo;
                    }
                    while (lo < hi && nums[hi] == nums[hi - 1])
                    {
                        --hi;
                    }
                    ++lo;
                    --hi;
                }
                else if ((nums[lo] + nums[hi] + nums[i]) > 0)
                    --hi;
                else
                    ++lo;
            }
            while (i < n && nums[i] == a)
            {
                ++i;
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