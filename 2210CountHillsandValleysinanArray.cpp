#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            if(nums[i] == nums[i-1])
                continue;
            int j = i - 1;
            int left = i;
            while (j >= 0) {
                if (nums[j] != nums[i]) {
                    left = j;
                    break;
                }
                --j;
            }
            if(left == i)
                continue;
            j = i + 1;
            int right = i;
            while(j < n){
                if(nums[j] != nums[i]){
                    right = j;
                    break;
                }
                ++j;
            }
            if(right == i)
                continue;
            cout<<i<<endl;
            if(nums[left] < nums[i] && nums[right] < nums[i])
                ++ans;
            if(nums[left] > nums[i] && nums[right] > nums[i])
                ++ans;
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