#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        for (int i = 0; i < n; i+=3)
        {
            if(i + 2 < n){
                if(nums[i+2] <= nums[i]+k){
                    ans.push_back({nums[i], nums[i+1], nums[i+2]});
                }
                else return {};
            }
            else return {};
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