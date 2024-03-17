#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>ump; //sum -> index
        
        ump[0] = -1;
        int sum = 0;
        int maxi = 0;
        
        for(int i=0;i<nums.size();++i){
            
            if(nums[i]) ++sum;
            else --sum;

            if(ump.find(sum) != ump.end())
                maxi = max(i - ump[sum],maxi);            
            else ump[sum] = i;
        }

        return maxi;
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