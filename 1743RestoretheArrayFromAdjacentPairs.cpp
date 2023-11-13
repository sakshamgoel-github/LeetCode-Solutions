#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    vector<int> ans;
    unordered_map<int, vector<int>> adj;

public:
    void dfs(int curr, int prev)
    {
        ans.push_back(curr);
        for (int child : adj[curr])
        {
            if (child != prev)
                dfs(child, curr);
        }
    }
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
    {
        for (auto x : adjacentPairs)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int start;
        for (auto x : adj)
        {
            if (x.second.size() == 1)
            {
                start = x.first;
                break;
            }
        }
        dfs(start, INT_MIN);
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