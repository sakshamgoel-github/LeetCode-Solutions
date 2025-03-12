#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

    class Solution
    {
    public:
        int maximumCount(vector<int> &nums)
        {
            int n = nums.size();
            int lo = 0, hi = n - 1, mid;
            int pos=-1;
            while (lo <= hi)
            {
                mid = (lo+hi)/2;
                if(nums[mid] < 1){
                    lo = mid+1;
                }
                else{
                    pos = mid;
                    hi = mid-1;
                }
            }
            int neg = -1;
            lo = 0; hi = n-1;
            while (lo <= hi)
            {
                mid = (lo+hi)/2;
                if(nums[mid] > -1){
                    hi = mid-1;
                }
                else{
                    neg = mid;
                    lo = mid + 1;
                }
            }
            pos = (pos == -1) ? 0 : (n-pos);
            neg = (neg == -1) ? 0 : (1+neg);
            return max(pos,neg);  
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