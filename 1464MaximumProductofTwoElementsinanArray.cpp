#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0, max2 = 0;
        for(int i=0;i<nums.size();++i){
            if(max1 == 0 || nums[i] >= max1){
                max2 = max1;
                max1 = nums[i];
            }
            else if(max2 == 0 || nums[i] > max2){
                max2 = nums[i];
            }
        }
        return ((max1 - 1) * (max2 - 1));
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