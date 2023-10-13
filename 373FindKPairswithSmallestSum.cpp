#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:

    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<vector<int>> ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> mh;

        int n = nums1.size();
        for (int i = 0; i < n; i++)
        {
            mh.push({nums1[i] + nums2[0],i,0});
        }

        int m = nums2.size();
        while (k && !mh.empty())
        {
            auto curr = mh.top();
            mh.pop();

            ans.push_back({nums1[curr[1]],nums2[curr[2]]});

            if ((curr[2] + 1) < m)
            {
                mh.push({nums1[curr[1]] + nums2[curr[2] + 1],curr[1],curr[2]+1});
            }
            --k;
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