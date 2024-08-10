#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    int N;
    unordered_map<string, int> ump;
    int MOD = 1e9 + 7;

public:
    int solve(char ch, int ind)
    {
        if (ind == N)
        {
            return 1;
        }
        string key = to_string(ch) + " " + to_string(ind);
        if (ump.find(key) != ump.end())
            return ump[key];
        int ans = 0;
        if (ch == 'a')
        {
            ans = (ans + solve('e', ind + 1)) % MOD;
        }
        else if (ch == 'e')
        {
            ans = (ans + solve('a', ind + 1)) % MOD;
            ans = (ans + solve('i', ind + 1)) % MOD;
        }
        else if (ch == 'i')
        {

            ans = (ans + solve('a', ind + 1)) % MOD;
            ans = (ans + solve('e', ind + 1)) % MOD;
            ans = (ans + solve('o', ind + 1)) % MOD;
            ans = (ans + solve('u', ind + 1)) % MOD;
        }
        else if (ch == 'o')
        {
            ans = (ans + solve('i', ind + 1)) % MOD;
            ans = (ans + solve('u', ind + 1)) % MOD;
        }
        else if (ch == 'u')
        {
            ans = (ans + solve('a', ind + 1)) % MOD;
        }
        return (ump[key] = (ans % MOD));
    }
    int countVowelPermutation(int n)
    {
        this->N = n;
        int ans = 0;
        ans = (ans + solve('a', 1))%MOD;
        ans = (ans + solve('e', 1))%MOD;
        ans = (ans + solve('i', 1))%MOD;
        ans = (ans + solve('o', 1))%MOD;
        ans = (ans + solve('u', 1))%MOD;
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