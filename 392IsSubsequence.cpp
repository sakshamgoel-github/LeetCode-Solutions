#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        int i = 0;
        for (int j = 0; j < m, i < n; j++)
        {
            if (s[i] == t[j])
                ++i;
        }
        return i == m;
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