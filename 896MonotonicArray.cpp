#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        if (nums.size() == 1)
            return true;
        bool inc = false, dec = false;
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i)
        {
            if (nums[i] < nums[i + 1])
                inc = true;
            if (nums[i] > nums[i + 1])
                dec = true;
        }
        if (inc & dec)
            return false;
        return true;
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