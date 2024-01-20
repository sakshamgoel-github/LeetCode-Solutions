#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int partitionString(string s)
    {
        int n = s.length(), ans = 1;
        int j = 0;
        int flag = 0;
        while (j < n)
        {
            int ch = s[j] - 'a';
            if (flag & (1 << ch))
            {
                flag = 0;
                ++ans;
            }
            flag = flag | (1<<ch);
            ++j;
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