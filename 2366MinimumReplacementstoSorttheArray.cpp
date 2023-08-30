#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    long long minimumReplacement(vector<int> &nums)
    {
        long long ans = 0;
        int n = nums.size();
        int smaller = INT_MAX;

        for (int i = n - 1; i >= 0; --i)
        {
            if (nums[i] > smaller)
            {
                int parts = nums[i] / smaller;
                if (nums[i] % smaller)
                    ++parts;
                ans += parts-1;
                smaller = nums[i] / parts;
            }
            else
                smaller = nums[i];
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
    vector<int> nums = {12, 9, 7, 6, 17, 19, 21};
    Solution obj;
    cout << obj.minimumReplacement(nums);
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}