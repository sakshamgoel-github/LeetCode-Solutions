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
        if (i >= n)
        {
            if (!target)
                ans.push_back(t);
            return;
        }
        if (!target)
        {
            ans.push_back(t);
            return;
        }
        if (target < 0)
        {
            return;
        }
        
            t.push_back(candidates[i]);
            solve(i, target - candidates[i], t, candidates);
            t.pop_back();
            solve(i + 1, target, t, candidates);
        
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        n = candidates.size();
        vector<int>t;
        solve(0,target,t,candidates);
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