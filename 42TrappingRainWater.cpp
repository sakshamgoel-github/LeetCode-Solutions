#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int l = 0, r = n - 1, leftMax = INT_MIN, rightMax = INT_MIN;
        int res = 0;
        while (l < r)
        {
            if (height[l] < height[r])
            {
                if(height[l] > leftMax)
                leftMax = height[l];
                else res += leftMax - height[l];
                ++l;
            }
            else
            {
                if(height[r] > rightMax)
                rightMax = height[r];
                else res += rightMax - height[r];
                --r;
            }
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