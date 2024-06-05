#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int longestPalindrome(string s)
    {
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        for (char &ch : s)
        {
            if (ch >= 'a')
                v1[ch - 'a']++;
            else
                v2[ch - 'A']++;
        }
        int ans = 0;
        int odd = 0;
        for (int i = 0; i < 26; ++i)
        {
            if (v1[i] % 2 == 0)
                ans += v1[i];
            else
            {
                ans += v1[i] - 1;
                odd = 1;
            }
        }
        for (int i = 0; i < 26; ++i)
        {
            if (v2[i] % 2 == 0)
                ans += v2[i];
            else
            {
                ans += v2[i] - 1;
                odd = 1;
            }
        }
        return ans + odd;
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