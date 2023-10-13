#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        vector<pair<int, int>> v;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            v.push_back({nums[i], cost[i]});
        }
        sort(v.begin(), v.end());

        vector<long long int> prefixSum(n, 0);
        prefixSum[0] = v[0].second;
        long long int totalSum = 0;
        for (int i = 1; i < n; i++)
        {
            prefixSum[i] = prefixSum[i-1] + 1LL * v[i].second;
            totalSum += cost[i];
        }

        long long int tempCost=0;

        for (int i = 1; i < n; ++i)
        {
            tempCost += (v[i].first - v[0].first) * 1LL * v[i].second;
        }

        long long ans = tempCost;
     

        for (int i = 1; i < n; i++)
        {   
            long long gap = v[i].first - v[i-1].first;
            tempCost += prefixSum[i-1]*1LL*gap;
            tempCost -= (prefixSum[n-1] - prefixSum[i-1]) * 1LL * gap;

            if(tempCost < ans)
            ans = tempCost;
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