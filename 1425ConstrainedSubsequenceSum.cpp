#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int constrainedSubsetSum(vector<int> &nums, int k)
    {
        vector<int> t = nums;
        priority_queue<pair<int, int>> mh;
        mh.push({t[0], 0});
        int ans = t[0];
        for (int i = 1; i < nums.size(); i++)
        {
            while (!mh.empty() && (i - mh.top().second) > k)
            {
                mh.pop();
            }
            int x = mh.top().first;
            t[i] = max(t[i], nums[i] + x);
            ans = max(ans,t[i]);
            mh.push({t[i], i});
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