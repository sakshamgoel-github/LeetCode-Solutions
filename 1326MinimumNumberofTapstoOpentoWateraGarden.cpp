#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int minTaps(int n, vector<int> &ranges)
    {
        vector<int> rightMax(n);
        for (int i = 0; i < ranges.size(); i++)
        {
            int l = max(0, i - ranges[i]);
            int r = min(n, ranges[i] + i);
            rightMax[l] = max(rightMax[l], r);
        }
        int reach = 0, curr = 0, ans = 0;
        for (int i = 0; i <= n; i++)
        {
            if (i > reach)
            {
                return -1;
            }
            if (i > curr)
            {
                ++ans;
                curr = reach;
            }
            reach = max(reach, rightMax[i]);
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