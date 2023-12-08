#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int minimumOneBitOperations(int n)
    {
        vector<long long> F(31);
        F[0] = 1;
        for (int i = 1; i < 31; i++)
        {
            F[i] = 2 * F[i - 1] + 1;
        }
        bool sign = false;
        int ans = 0;
        for (int i = 30; i >= 0; --i)
        {
            int ithBit = ((1 << i) & n);
            if (!ithBit)
                continue;
            if (sign)
            {
                ans -= F[i];
            }
            else
                ans += F[i];
            sign = !sign;
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