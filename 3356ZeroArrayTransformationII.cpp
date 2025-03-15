#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
public:
    bool check(vector<int> &nums, vector<vector<int>> &queries, int k)
    {
        int n = nums.size();
        vector<int> v(n, 0);
        for (int i = 0; i <= k; i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            v[l] += val;
            if ((r + 1) < n)
            {
                v[r + 1] -= val;
            }
        }
        for (int i = 1; i < n; ++i)
        {
            v[i] += v[i - 1];
        }
        for (int i = 0; i < n; i++)
        {
            if (v[i] < nums[i])
                return false;
        }
        return true;
    }
    bool checkAllZeroes(vector<int>&nums){
        for(int &x: nums){
            if(x!=0) return false;
        }
        return true;
    }
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {   
        if(checkAllZeroes(nums))
            return 0;
        int n = queries.size();
        int lo = 0, hi = n-1, mid; 
        int k = -1;

        while (lo <= hi) 
        {
            mid = (lo + hi) / 2;
            if (check(nums, queries, mid))
            {
                k = mid+1;
                hi = mid-1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return k;
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