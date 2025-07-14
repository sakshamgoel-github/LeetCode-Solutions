#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        unordered_map<int,vector<int>>ump;
        vector<int>v;
        vector<int>indices;
        vector<int>ans;

        int n = nums.size();
        for(int i=0;i<n;++i){
            ump[nums[i]].push_back(i);
            v.push_back(nums[i]);
        }    

        sort(v.begin(), v.end());

        for(int i = n - k;i<n;++i){
            int ele = v[i];
            int ind = ump[ele].back();
            ump[ele].pop_back();
            indices.push_back(ind);
        }

        sort(indices.begin(), indices.end());

        for(int i: indices){
            ans.push_back(nums[i]);
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