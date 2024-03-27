#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;
        while (i < n)
        {
            if (nums[i] == 1)
                break;
            ++i;
        }
        if (i == n)
            return 1;
        for(int i=0;i<n;++i){
            if(nums[i] <= 0 || nums[i] > n)
                nums[i]=1;
        }
        for (int i = 0; i < n; ++i)
        {
            int ind = abs(nums[i]) - 1;
            if(nums[ind] > 0)
                nums[ind] = nums[ind] * -1;
            
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                return (i + 1);
        }
        return (n + 1);
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