#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        int lo = 0, hi = n - 1;
        while ((hi - lo) > 1)
        {
            int mid = (hi - lo) / 2 + lo;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];
            if(nums[mid] != nums[mid+1]){
                if(mid & 1){
                    lo = mid + 1;
                }
                else hi = mid - 1;
            }
            else{
                if(mid & 1){
                    hi = mid - 1;
                }
                else lo = mid + 1;
            }
        }
        if (hi == (n - 1))
            return nums[hi];
        return nums[lo];
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