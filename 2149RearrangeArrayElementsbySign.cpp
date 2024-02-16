#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int>ans(n);
        int pos = 0, neg = 1;
        int ind = 0;
        while (ind < n)
        {
            if(nums[ind] > 0){
                ans[pos] = nums[ind];
                ++pos;
                ++pos;
            }
            else{
                ans[neg] = nums[ind];
                ++neg;
                ++neg;
            }
            ++ind;
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