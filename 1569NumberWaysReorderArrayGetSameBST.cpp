#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    vector<vector<long long int>> pascal;
    long long int MOD = 1e9 + 7;

public:

    long long int solve(vector<int>&nums){
        int n = nums.size();
       
        if(n<=2)
        return 1;

        int root = nums[0];
        vector<int>leftNums;
        vector<int>rightNums;

        for (int i = 1; i < n; i++)
        {
            if(nums[i] < root){
                leftNums.push_back(nums[i]);
            }
            else {
                rightNums.push_back(nums[i]);
            }
        }

        long long int x = solve(leftNums)%MOD;
        long long int y = solve(rightNums)%MOD;

        long long int z = pascal[n-1][leftNums.size()] % MOD;
        z = (z*x)%MOD;
        z = (z*y)%MOD;

        return z;

    }
    int numOfWays(vector<int> &nums)
    {   
        int n = nums.size();

        pascal.resize(n+1);
        for (int i = 0; i <= n; i++)
        {   
            pascal[i] = vector<long long int>(i+1,1);
            for (int j = 1; j < i; j++)
            {
                pascal[i][j] = (pascal[i-1][j-1] + pascal[i-1][j])%MOD; 
            }
        }

        long long int ans = solve(nums)%MOD;
        return ans-1;
    }
};

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    Solution obj;
    vector<int>nums = {1,2,3};
    cout<<obj.numOfWays(nums);
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}