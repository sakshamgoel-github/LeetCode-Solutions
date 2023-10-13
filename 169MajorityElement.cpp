#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0, ans = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!count)
            {
                ans = nums[i];
                ++count;
            }
            else
            {
                if (ans != nums[i])
                    --count;
                else
                    ++count;
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