#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
    
class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {

        int n = nums.size();
        int ans = 0;

        vector<unordered_map<int, int>> t(n);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {

                int diff = nums[i] - nums[j];
                int cnt = 1;

                if (t[j].count(diff))
                    cnt = t[j][diff];

                t[i][diff] = 1 + cnt;
                ans = max(ans, t[i][diff]);
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