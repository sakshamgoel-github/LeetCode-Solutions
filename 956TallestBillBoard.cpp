#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
    int N;
    vector<int> rods;
    vector<vector<int>> t;

public:
    Solution()
    {
        t.resize(21, vector<int>(10005, -1));
    }
    
    int solve(int i, int d, vector<vector<int>> &t)
    {
        if (i == N)
        {
            if (!d)
                return t[i][d+5000] = 0;
            return (INT_MIN + 1);
        }
        if (t[i][d+5000] != -1)
            return t[i][d+5000];

        int ans1 = solve(i + 1, d,t);
        int ans2 = rods[i] + solve(i + 1, d + rods[i],t);
        int ans3 = rods[i] + solve(i + 1, d - rods[i],t);

        return t[i][d+5000] = max({ans1, ans2, ans3});
    }
    
    int tallestBillboard(vector<int> &rods)
    {
        int ans = 0;
        this->N = rods.size();
        this->rods = rods;
        ans = solve(0, 0, t);
        return ans / 2;
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