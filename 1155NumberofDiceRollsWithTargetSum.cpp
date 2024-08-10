#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    int t[31][1001];
    int MOD = 1e9+7;
public:
    Solution() { memset(t, -1,sizeof(t)); }
    int numRollsToTarget(int n, int k, int target)
    {
        if (target < 0)
            return 0;
        if (n == 0)
        {
            return target == 0;
        }
        if(t[n][target] != -1) return t[n][target];
        int ans = 0;
        for (int i = 1; i <= k; i++)
        {
            ans = (ans + numRollsToTarget(n - 1, k, target - i)) % MOD;
        }
        ans = ans % MOD;
        return t[n][target] = ans;
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