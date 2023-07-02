#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
private:
    int result;
    vector<pair<int, int>> adj[1000];

    void dfs(int node, vector<bool> &vis)
    {
        vis[node] = true;
        for(auto x:adj[node]){
            if(x.second<result)
            result = x.second;
            if(!vis[x.first])
            dfs(x.first,vis);
        }
    }

public:
Solution(){
    result = INT_MAX;
}
    int minScore(int n, vector<vector<int>> &roads)
    {
        vector<bool> vis(n + 1, false);
        for (auto &x : roads)
        {
            int node1 = x[0];
            int node2 = x[1];
            int dis = x[2];
            adj[node1].push_back({node2, dis});
            adj[node2].push_back({node1, dis});
        }
        dfs(1, vis);
        return result;
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