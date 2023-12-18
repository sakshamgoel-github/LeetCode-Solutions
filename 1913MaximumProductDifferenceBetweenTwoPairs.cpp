#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int w = 0, x = 0, y = 1e4+1, z = 1e4+1;
        for(int i=0;i<nums.size();++i){
            if( nums[i] >= w){
                x = w;
                w = nums[i];
            }
            else if(nums[i] > x){
                x = nums[i];
            }
            if(nums[i] <= y){
                z = y;
                y = nums[i];
            }
            else if(nums[i] < z){
                z = nums[i];
            }
        }
        return (w*x - y*z);
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