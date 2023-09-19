#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    bool isSorted(vector<int>&nums){
        for (int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i] > nums[i+1]) return false;
        }
        return true;
        
    }
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if(isSorted(nums)) return i;
            rotate(nums.begin(), nums.begin()+nums.size()-1, nums.end());

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