#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int minOperations(string s)
    {
        int ans1 = 0;
        char ch = '0';
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ch)
                ++ans1;
            if(ch == '0') ch = '1';
            else ch = '0';
        }
        ch = '1';
        int ans2 = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ch)
                ++ans2;
            if(ch == '0') ch = '1';
            else ch = '0';
        }
        return min(ans1, ans2);
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