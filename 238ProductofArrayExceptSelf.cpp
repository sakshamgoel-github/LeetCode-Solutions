#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n);
        int prod = 1;
        for (int i = 0; i < n; i++)
        {
            res[i] = prod;
            prod = nums[i] * prod;
        }
        prod = 1;
        for (int i = n-1; i >= 0; i--)
        {
            res[i] *= prod;
            prod *= nums[i];
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

    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}