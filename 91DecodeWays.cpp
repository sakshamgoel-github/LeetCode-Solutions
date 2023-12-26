#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    int n;
    string s;
    vector<int> t;

public:
    int solve(int i)
    {
        if (i == n)
            return t[i] = 1;
        if (s[i] == '0')
            return t[i] = 0;
        if (t[i] != -1)
            return t[i];
        int res;
        res = solve(i + 1);
        if (i + 1 < n)
        {
            if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
                res += solve(i + 2);
        }
        return t[i] = res;
    }
    int numDecodings(string s)
    {
        this->s = s;
        this->n = s.length();
        return solve(0);
    }
    Solution() { t.resize(101, -1); }
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