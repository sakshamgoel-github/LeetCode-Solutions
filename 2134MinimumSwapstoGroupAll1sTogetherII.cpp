#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;++i)
            nums.push_back(nums[i]);
        int winSize = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i] == 1)
                ++winSize;
        }    
        winSize /= 2;
        int zeroes = 0;
        for(int i=0;i<winSize;++i){
            if(nums[i] == 0)
                ++zeroes;
        }
        int j=winSize-1,i=0;
        int ans = zeroes;
        while(j < nums.size() && j > i){
            ans = min(zeroes,ans);
            ++j;
            if(j < nums.size() && nums[j] == 0)
                ++zeroes;
            if(nums[i] == 0)
                --zeroes;
            ++i;
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