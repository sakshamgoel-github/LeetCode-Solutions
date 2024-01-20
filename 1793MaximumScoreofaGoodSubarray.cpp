#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i=k-1, j=k+1,n=nums.size(),result=nums[k],mini=nums[k];
        while(i >= 0 || j < n){
            int left = i >= 0 ? nums[i]:0;
            int right = j < n ? nums[j]:0;
            if(left > right){
                mini = min(mini, left);
                result = max(result, mini*(j-i));
                --i;
            }
            else{
                mini = min(mini,right);
                result = max(result, mini*(j-i));
                ++j;
            }
        }
        return result;
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