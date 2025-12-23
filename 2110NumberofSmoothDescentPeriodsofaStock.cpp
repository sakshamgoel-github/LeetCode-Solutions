#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    long long getDescentPeriods(vector<int> &prices)
    {
        long long ans = 0;
        int curr = 1;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] + 1 == prices[i - 1]){
                ++curr;
            } else {
                ans = ans + (curr * 1LL * (curr+1))/2LL;
                curr = 1;
            }
        }
        ans = ans + (curr * 1LL * (curr+1))/2LL;
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