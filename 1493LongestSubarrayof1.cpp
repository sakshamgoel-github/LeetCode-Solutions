#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0, j = 0, res = 0, zeros = 0, t = 0;
        while (j < n)
        {   
            if (!nums[j])
            {
                if (!zeros)
                {
                    ++zeros;
                }
                else
                {
                    while(nums[i]){
                        ++i;
                    }
                    ++i;
                }
            }
            t = j - i;
            res = max(t, res);
            ++j;
        }
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