#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    vector<vector<int>> t;
    int arrLen;
    int MOD = 1e9 + 7;

public:
    int solve(int ind, int steps)
    {
        if (ind < 0 || ind >= arrLen)
            return 0;
        if (steps == 0)
            return ind == 0;
        if (t[ind][steps] != -1)
            return t[ind][steps];

        int res = 0;
        res = (res + solve(ind + 1, steps - 1)) % MOD;
        res = (res + solve(ind, steps - 1)) % MOD;
        res = (res + solve(ind - 1, steps - 1)) % MOD;

        return t[ind][steps] = (res % MOD);
    }
    int numWays(int steps, int arrLen)
    {
        this->arrLen = min(steps / 2 + 1, arrLen);
        t.resize(this->arrLen + 1, vector<int>(steps + 1, -1));
        return solve(0, steps);
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