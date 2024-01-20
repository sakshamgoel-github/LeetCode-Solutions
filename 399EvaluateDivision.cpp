#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    unordered_map<string, vector<pair<string, double>>> graph;

public:
    double dfs(string a, string b, unordered_map<string, bool> &vis)
    {
        vis[a] = true;
        if (a == b)
            return 1.0;
        double ans;
        for (auto child : graph[a])
        {
            if (!vis[child.first])
            {
                ans = dfs(child.first, b,vis);
                if (ans!=-1)
                return child.second * ans;
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        int i = 0;
        for (auto x : equations)
        {
            graph[x[0]].push_back({x[1], values[i]});
            graph[x[1]].push_back({x[0], 1.0 / values[i]});
            ++i;
        }
        vector<double> ans;
        for (auto query : queries)
        {
            if (graph.find(query[0]) == graph.end() || graph.find(query[1]) == graph.end())
                ans.push_back(-1.0);
            else
            {
                unordered_map<string, bool> vis;
                double x = dfs(query[0], query[1], vis);
                ans.push_back(x);
            }
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
    vector<vector<string>>equations = {{"x1","x2"},{"x2","x3"},{"x1","x4"},{"x2","x5"}};
    vector<double>values = {3.0,0.5,3.4,5.6};
    vector<vector<string>>queries = {{"x2","x4"}};
    Solution obj;
    vector<double>ans = obj.calcEquation(equations,values,queries);
    for(auto a: ans)
    cout<<a<<" ";
    cout<<endl;
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}