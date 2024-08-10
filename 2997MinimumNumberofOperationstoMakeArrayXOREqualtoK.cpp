#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x = 0;
        int n = nums.size();
        for(int i=0;i<n;++i){
            x = x ^ nums[i];
        }   
        int ans = 0;
        for(int i=0;i<32;++i){
            int xBit = x & 1;
            int kBit = k & 1;
            if(xBit != kBit)
                ++ans;
            x = x >> 1;
            k = k >> 1;
        }
        return ans;
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