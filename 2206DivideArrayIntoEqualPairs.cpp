#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            vector<bool>v(500,1);
            for(int i=0;i<nums.size();++i){
                v[nums[i]] = !v[nums[i]];
            }    
            for(int i=0;i<500;++i){
                if(!v[i]) return false;
            }
            return true;
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