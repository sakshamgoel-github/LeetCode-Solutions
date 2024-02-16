#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.length();
        int ans = 0;
        vector<vector<bool>> v(n, vector<bool>(n, false));
        for (int len = 1; len <= n; len++)
        {
            for (int i = 0; i + len - 1 < n; i++)
            {
                int j = i + len - 1;
                if (i == j)
                    v[i][j] = true;
                else if (i + 1 == j)
                {
                    if (s[i] == s[j])
                        v[i][j] = true;
                }
                else
                {
                    if (s[i] == s[j] && v[i + 1][j - 1])
                        v[i][j] = true;
                }
                ans += v[i][j];
            }
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