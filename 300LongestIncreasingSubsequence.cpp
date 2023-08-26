#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {   
        int n = nums.size();
        vector<int> t(n + 1, 1);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j]){
                    t[i] = max(t[i],t[j] + 1);
                }
            }
            ans = max(t[i],ans);
            
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