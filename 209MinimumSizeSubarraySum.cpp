#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int i = 0, j = 0, res = 1e5 + 1, t = 0;
        while (j < n)
        {
            if (t < target)
            {
                t += nums[j];
            }
            while (i<=j && t >= target)
            {
                res = min(j-i+1,res);
                t -= nums[i];
                ++i;                
            }
            ++j;
        }
        if (res == 1e5+1)
        return 0;
        return res;
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