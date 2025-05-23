#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> temp(n, 0);
        for (auto x : queries)
        {
            int l = x[0];
            int r = x[1];
            ++temp[l];
            if ((r + 1) < n)
                --temp[r + 1];
        }
        int x = temp[0];
        if(x < nums[0]) return false;
        for (int i = 1; i < n; i++)
        {
            x += temp[i];            
            if(x < nums[i]) return false;
        }
        return true;
    };
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