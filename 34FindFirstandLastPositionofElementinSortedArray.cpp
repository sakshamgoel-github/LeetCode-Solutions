#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int lo = 0, hi = n - 1;
        int idx = -1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (nums[mid] == target)
            {
                hi = mid - 1;
                idx = mid;
            }
            else if (nums[mid] > target)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        vector<int> ans;
        ans.push_back(idx);
        idx = -1, lo = 0, hi = n - 1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (nums[mid] == target)
            {
                lo = mid + 1;
                idx = mid;
            }
            else if (nums[mid] > target)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        ans.push_back(idx);
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