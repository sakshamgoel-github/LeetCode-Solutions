#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    int MOD = 1e9+7;
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int>total;
        for (int &x:nums)
        {
            total[x]++;
        }
        int ans = 0;
        unordered_map<int,int>seen;
        for (int i = 0; i < nums.size(); i++)
        {
            int a = nums[i]*2;
            int l = seen[a];
            int r = total[a] - l;
                r = r - (a == 0);
            ans = (ans + (l*1LL*r) % MOD) % MOD;
            seen[nums[i]]++;
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