#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int num = nums[0], freq = 1, n = nums.size();
            for(int i=0;i<n;++i){
                if(nums[i] == num){
                    ++freq;
                } else {
                    --freq;
                    if(freq == 0){
                        num = nums[i];
                        ++freq;
                    }
                }
            }
            freq = 0;
            for(int i=0;i<n;++i){
                if(nums[i] == num)
                    ++freq;
            }
            int freq1 = 0;
            for(int i=0;i<n;++i){
                if(num == nums[i]){
                    ++freq1;
                    if((freq1 > (i+1)/2) && (freq - freq1 > (n-i-1)/2))
                        return i;
                }
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