#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        long long int prev = 1;
        vector<int> ans(rowIndex + 1, 1);
        for (int i = 1; i <= rowIndex / 2; i++)
        {
            long long int t = (prev * (rowIndex - i + 1)) / i;
            ans[i] = t;
            ans[rowIndex - i] = t;
            prev = t;
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