#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            int n = nums.size();
            int less_ptr, more_ptr,eq_ptr;
            int l = 0, e = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] < pivot)
                    ++l;
                else if (nums[i] == pivot)
                    ++e;
            }
            less_ptr = 0;
            more_ptr = l + e;
            eq_ptr = l;
            vector<int> ans(n);
            int i = 0;
            while (i < n) {
                if (nums[i] < pivot)
                    ans[less_ptr++] = nums[i];
                else if (nums[i] > pivot)
                    ans[more_ptr++] = nums[i];
                else ans[eq_ptr++] = nums[i];
                ++i;
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