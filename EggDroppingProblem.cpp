#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
private:
    vector<vector<int>> t;
    int solve(int e, int f)
    {
        if (e == 1 || f == 0 || f == 1)
            return f;
        if (t[e][f] != -1)
            return t[e][f];
        int ans = INT_MAX;
        for (int i = 1; i <= f; i++)
        {
            int eggNotBreak = solve(e, f - i) + 1;
            int eggBreak = solve(e - 1, i - 1) + 1;
            int t = max(eggNotBreak, eggBreak);
            ans = min(ans, t);
        }
        return t[e][f] = ans;
    }

public:
    int eggDrop(int n, int k)
    {
        // your code here
        t.resize(n+1,vector<int>(k+1,-1));
        return solve(n,k);
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