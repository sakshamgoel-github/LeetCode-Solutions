#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    int goal, n, k;
    int MOD = 1e9 + 7;
    vector<vector<int>> t;

public:
    int solve(int total, int unique)
    {
        if (total == goal)
        {
            if (unique == n)
            {
                return 1;
            }
            return 0;
        }
        if (t[total][unique] != -1)
            return t[total][unique];
        long long int result = 0;
        if (unique < n)
            result = (result + (n - unique) * 1LL * solve(total + 1, unique + 1) % MOD) % MOD;
        if (unique > k)
            result = (result + (unique - k) * 1LL * solve(total + 1, unique) % MOD) % MOD;

        return t[total][unique] = result;
    }
    int numMusicPlaylists(int n, int goal, int k)
    {
        this->n = n;
        this->goal = goal;
        this->k = k;
        t.resize(101, vector<int>(101, -1));
        return solve(0, 0);
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