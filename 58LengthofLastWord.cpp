#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int i = s.length() - 1;
        while (s[i] == ' ')
        {
            --i;
        }
        int ans = 0;
        while (i >= 0 && s[i] != ' ')
        {
            --i;
            ++ans;
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