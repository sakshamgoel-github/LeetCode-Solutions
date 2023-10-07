#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    int n, m, k;
    int MOD = 1e9 + 7;
    int t[51][51][101];

public:
    int solve(int idx, int searchCost, int maxSoFar)
    {
        if (idx == n)
        {
            if (searchCost == k)
                return 1;
            return 0;
        }
        if (maxSoFar != -1 && t[idx][searchCost][maxSoFar] != -1)
        {
            return t[idx][searchCost][maxSoFar];
        }
        int result = 0;
        for (int i = 1; i <= m; ++i)
        {
            if (i > maxSoFar)
            {
                result = (result + solve(idx + 1, searchCost + 1, i)) % MOD;
            }
            else
            {
                result = (result + solve(idx + 1, searchCost, maxSoFar)) % MOD;
            }
        }
        if (maxSoFar != -1)
            t[idx][searchCost][maxSoFar] = result % MOD;
        return result % MOD;
    }
    int numOfArrays(int n, int m, int k)
    {
        this->n = n;
        this->m = m;
        this->k = k;
        memset(t, -1, sizeof(t));
        return solve(0, 0, -1);
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