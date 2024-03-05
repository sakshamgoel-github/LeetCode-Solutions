#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            nums[i]*=nums[i];
        }
        if(n == 1) return nums;
        if(n == 2){
            if(nums[0] > nums[1]) 
                swap(nums[0], nums[1]);
            return nums;
        }
        int lo = 0, hi = n-1;
        while (lo <= hi)
        {
            int mid = (lo+hi)/2;
            if(nums[mid] < nums[mid+1] && nums[mid] < nums[mid-1])
                break;
            
        }
        
        return nums;              
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