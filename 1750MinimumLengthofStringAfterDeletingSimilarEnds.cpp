#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int minimumLength(string s)
    {
        int i = 0, j = s.length() - 1;
        int cnt = 0;
        while (i < j)
        {
            if (s[i] != s[j])
                break;
            while (i + 1 < j && s[i] == s[i + 1])
            {
                ++i;
                ++cnt;
            }
            while (j - 1 > i && s[j] == s[j - 1])
            {
                --j;
                ++cnt;
            }
            cnt += 2;
            ++i;
            --j;
        }
        return s.length() - cnt;
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