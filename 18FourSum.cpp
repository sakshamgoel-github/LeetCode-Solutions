#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        int n = nums.size();
        int i = 0, left, right;
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        
        for (; i < n-3; i++) {
            if ((i > 0) && (nums[i] == nums[i - 1]))
                continue;
            
            int j = i + 1;  
            for (; j < n-2; j++) {
                if ((j > i+1) && (nums[j] == nums[j - 1]))
                    continue;
                
                left = j + 1;
                right = n - 1;
                
                if (left >= n)
                    break;
                
                long long int sum;
                
                while (left < right) {
                    sum = nums[i]*1LL + nums[j]*1LL + nums[left]*1LL + nums[right]*1LL;
                    
                    if (sum == target) {
                        s.insert({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                    } else if (sum < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }
        
        vector<vector<int>> ans;
        for (auto &it : s) {
            ans.push_back(it);
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