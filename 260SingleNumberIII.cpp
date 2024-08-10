#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() == 2)
            return nums;
        long long xore = 0;
        for(int &x: nums)
            xore = xore ^ 1LL*x;
        long long mask = xore & (-xore);
        int n1 = 0,n2 = 0;
        for(int &x: nums){
            if(x & mask)
                n1 = n1 ^ x;
            else n2 = n2 ^ x;
        }    
        return {n1,n2};
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