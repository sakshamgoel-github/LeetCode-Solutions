#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1,mid;
        while (lo<=hi)
        {
            mid = (hi-lo)/2 + lo;
            if(nums[mid] == target)
            return mid;
            else if(nums[mid] > target)
            hi = mid-1;
            else lo = mid+1;
        }
        return -1;
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