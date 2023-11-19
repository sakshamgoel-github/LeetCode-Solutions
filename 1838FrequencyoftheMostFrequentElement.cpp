#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{

public:
    int maxFrequency(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 0, l = 0;
        long long newSum;
        long long originalSum = 0;
        
        for (int i = 0; i < n; i++)
        {   
            newSum = (i-l+1)*1LL*nums[i];
            originalSum += nums[i];
            int ops = newSum - originalSum;
            if(ops > k){
                originalSum -= nums[l];
                ++l;
            }
            else{
                ans = max(ans, i-l+1);
            }
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