#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int ans = 0;
        for (int i = 0; i < 32; ++i)
        {
            bool x = a & 1;
            bool y = b & 1;
            bool z = c & 1;

            if ((x | y) ^ z)
            {
                if (z)
                {
                    ++ans;
                }
                else
                {
                    if (x & y)
                    {
                        ans += 2;
                    }
                    else
                    {
                        ++ans;
                    }
                }
            }
            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
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
    vector<vector<int>>v;
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}