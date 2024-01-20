#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> ump;
        for (int i = 0; i < n; ++i)
        {
            ump[nums[i]]++;
        }
        int ans = 0;
        for (auto x: ump)
        {   
            if(x.second == 1) return -1;
            ans += (x.second/3) + !(x.second % 3 == 0);
        }
        return ans;
    }
};
// https://www.linkedin.com/in/nikita-nath-99733019a/
int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}