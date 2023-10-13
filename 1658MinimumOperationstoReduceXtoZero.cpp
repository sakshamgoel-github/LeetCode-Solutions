#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        unordered_map<int, int> ump;
        int n = nums.size();
        int sum = 0;
        ump[0] = -1;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            ump[sum] = i;
        }
        if(sum < x) return -1;
        int target = sum - x;
        int ans = -1;
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (ump.find(sum - target) != ump.end())
            {
                ans = max(ans, i - ump[sum - target]);
            }
        }
        return ans == -1 ? -1 : (n - ans);
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