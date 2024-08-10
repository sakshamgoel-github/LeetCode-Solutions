#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> ump;
        for (auto n : nums)
        {   ump.insert(n);
        }
        int ans = 0;
        for (auto x : ump)
        {
            if (ump.find(x-1) == ump.end())
            {
                int t = 0;
                int currNum = x;
                while (ump.find(currNum) != ump.end())
                {
                    ++t;
                    ++currNum;
                }
                ans = max(t, ans);
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