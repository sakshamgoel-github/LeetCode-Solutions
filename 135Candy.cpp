#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        int prev, sum = 0;
        vector<int> ans(n, 1);
        prev = 1;
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
                ans[i] = max(ans[i], ans[i - 1] + 1);
        }
        for (int i = n-2; i >= 0; --i)
        {
            if(ratings[i] > ratings[i+1])
                ans[i] = max(ans[i],ans[i+1]+1);
        }
        return sum;
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