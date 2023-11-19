#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int reductionOperations(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int smallest = nums[0];
        int ans = 0;
        int cnt = 0;
        int prev = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {   
            if(nums[i] != prev){
                prev = nums[i];
                ++cnt;
            }
            if (nums[i] != smallest)
            {
                ans += cnt;
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