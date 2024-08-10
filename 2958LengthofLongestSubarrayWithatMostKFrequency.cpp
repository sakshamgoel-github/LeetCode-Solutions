#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>ump;
        int i=0,j=0,l=0;
        while (j<n)
        {
            ump[nums[j]]++;
            while (ump[nums[j]] > k)
            {
                ump[nums[i]]--;
                ++i;
            }
            l = max(l,j-i+1);
            ++j;
        }
        return l;
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