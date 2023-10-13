#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    int n;
    vector<vector<int>> ans;

public:
    void solve(int i, int target, vector<int> &t, vector<int> &candidates)
    {
        if (!target)
        {
            ans.push_back(t);
            return;
        }
        if (i >= n || target < 0)
        {
            return;
        }
        while (i < n)
        {
            t.push_back(candidates[i]);
            solve(i + 1, target - candidates[i], t, candidates);
            t.pop_back();
            while (i < (n - 1) && candidates[i] == candidates[i + 1])
            {
                ++i;
            }
            ++i;
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int> t;
        solve(0, target, t, candidates);
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