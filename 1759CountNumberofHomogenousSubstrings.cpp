#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{   long long int MOD = 1e9+7;
public:
    int countHomogenous(string s)
    {
        int n = s.length();
        int ans = 0;
        int l = 1;
        char ch = s[0];
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ch)
                ++l;
            else
            {
                ans = (ans + (l * 1LL * (l + 1) / 2) % MOD) % MOD;
                l = 1;
                ch = s[i];
            }
        }
        ans = (ans + (l * 1LL * (l + 1) / 2) % MOD) % MOD;
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