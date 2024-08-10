#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> st;
        unordered_map<int, int> ump;
        int n = nums2.size();
        vector<int> nge(n, -1);
        for (int i = n - 1; i >= 0; --i)
        {
            ump[nums2[i]] = i;
            while (!st.empty() && st.top() < nums2[i])
            {
                st.pop();
            }
            if (!st.empty())
                nge[i] = st.top();
            st.push(nums2[i]);
        }
        vector<int> ans;
        for (auto x : nums1)
        {
            ans.push_back(nge[ump[x]]);
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