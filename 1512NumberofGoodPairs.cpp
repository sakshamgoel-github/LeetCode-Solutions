#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
       int n = nums.size(), cnt= 0;
       for(int i=0;i<n;++i){
           for(int j=i+1;j<n;++j){
               if(nums[i] == nums[j]) ++cnt;
           }
       } 
       return cnt;
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