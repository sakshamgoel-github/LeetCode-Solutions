#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int n = nums.size();
        int j = 0;
        while (j < n && nums[j] != val)
        {
            ++j;
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != val && i > j)
            {
                swap(nums[i], nums[j]);
                while (j < n && nums[j] != val)
                {
                    ++j;
                }
            }
        }
        int k = 0;
        while (k < n && nums[k] != val)
        {
            ++k;
        }
        return k;
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