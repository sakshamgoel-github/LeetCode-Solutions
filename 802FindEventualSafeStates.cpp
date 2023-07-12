#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    unordered_map<int, bool> ump;
    bool solve(int node, vector<vector<int>> &graph)
    {
        if (ump.find(node) != ump.end())
            return ump[node];
        ump[node] = false;
        for (auto child : graph[node])
        {
            if (!solve(child, graph))
            {
                return false;
            }
        }
        ump[node] = true;
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (solve(i, graph))
                ans.push_back(i);
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