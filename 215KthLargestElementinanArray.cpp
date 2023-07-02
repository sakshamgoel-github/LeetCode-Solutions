#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    int quickSelect(vector<int> &nums, int k)
    {
        vector<int> left;
        vector<int> right;
        vector<int> middle;

        int pivot = nums[0];
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < pivot)
            {
                right.push_back(nums[i]);
            }
            else if (nums[i] > pivot)
            {
                left.push_back(nums[i]);
            }
            else
                middle.push_back(nums[i]);
        }
        if (k <= left.size())
        {
            return quickSelect(left, k);
        }
        else if (k > (left.size() + middle.size()))
        {
            return quickSelect(right, k - left.size() - middle.size());
        }
        return pivot;
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return quickSelect(nums,k);
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
