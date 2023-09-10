#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int countOrders(int n)
    {
        if (n == 1)
            return 1;
        long long int res = 1;
        long long int MOD = 1e9 + 7;
        for (int i = 2; i <= n; ++i)
        {
            long long int spaces = 2 * i - 1;
            long long int current_possibility = (spaces * (spaces + 1)) / 2;
            res = (res * current_possibility) % MOD;
        }
        return res;
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