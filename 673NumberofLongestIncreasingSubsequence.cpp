#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> t(n, 1);
        vector<int> cnt(n, 1);
        for (int i = 1; i < n; i++)
        {
            int ele = nums[i];
            for (int j = 0; j < i; j++)
            {
                if (ele > nums[j])
                {
                    if (t[i] == (t[j] + 1))
                    {
                        cnt[i] += cnt[j];
                    }
                    else if ((t[j] + 1) > t[i])
                    {
                        t[i] = t[j] + 1;
                        cnt[i] = cnt[j];
                    }
                }
            }
        }
        int maxi = *max_element(begin(t),end(t));
        int res = 0;
        for(int i=0;i<n;++i){
            if(t[i] == maxi)
            res += cnt[i];
        }
        return res;
    }
};

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    Solution obj;
    vector<int> nums = {1, 3, 5, 4, 7};
    obj.findNumberOfLIS(nums);
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}