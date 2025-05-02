#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int n = nums.size();
            int ans = 0;
            for(int i=2;i<n;++i){
                int f = nums[i-2];
                int s = nums[i-1];
                int t = nums[i];
                if(s&1) continue;
                if((f+t) == (s/2)) ++ans;
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