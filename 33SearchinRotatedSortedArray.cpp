#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n-1, mid,L,H,MID;
        int rotated = 0;
        if(nums[0] > nums[n-1]){
            while(lo <= hi){
                mid = (lo+hi)/2;
                if(nums[mid] > nums[mid+1]){
                    rotated = mid+1;
                    break;
                }
                if(nums[mid] > nums[n-1]){
                    lo = mid+1;
                }
                else hi = mid-1;
            }
        }
        lo = 0, hi = n-1;
        while(lo < hi){
            mid = (lo + hi)/2;
            MID = (mid+rotated)%n;
            if(nums[MID] == target)
            return MID;
            else if (nums[MID] > target){
                hi = mid-1;
            }
            else lo = mid+1;
        }
        L = (lo+rotated)%n;
        if(nums[L] == target)
        return L;
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