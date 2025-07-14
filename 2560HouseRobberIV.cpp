#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    bool check(vector<int> &nums, int k, int capability)
    {
        int houses = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= capability)
            {
                ++houses;
                ++i;
            }
        }
        return (houses >= k);
    }
    int minCapability(vector<int> &nums, int k)
    {
        int lo = 1, hi = 1e9;
        int ans;
        while (lo <= hi)
        {
            int mid = (hi - lo) / 2 + lo;
            if (check(nums, k, mid))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
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