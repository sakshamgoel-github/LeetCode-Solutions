#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int j = n - 2;
        int i;
        while (j>=0)
        {
            if(nums[j] < nums[j+1])
            {
                break;
            }        
            --j;
        }
        if(j<0){
            reverse(nums.begin(),nums.end());
        }              
        else {
            for(i = n-1;i>=0;--i){
                if(nums[i]>nums[j]){
                    break;
                }
            }

            swap(nums[j],nums[i]);
            reverse(nums.begin() + j + 1,nums.end());
        }
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