#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    vector<vector<int>> graph;
    int n;
    int dfs(int node,vector<bool>&vis)
    {
        vis[node] = true;
        int size = 0;
        for (auto child : graph[node])
        {
            if (!vis[child])
                size += dfs(child,vis);
        }
        return size + 1;
    }

public:
    int maximumDetonation(vector<vector<int>> &bombs)
    {
        this->n = bombs.size();
        graph.resize(n);
        for (int i = 0; i < n; i++)
        {
            int x1 = bombs[i][0];
            int y1 = bombs[i][1];
            int r = bombs[i][2];

            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;

                int x = x1-bombs[j][0];
                int y = y1-bombs[j][1];

                if (x*1LL*x + y*1LL*y <= r*1LL*r)
                    graph[i].push_back(j);
            }
        }
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            vector<bool>vis(n,false);
            int temp = dfs(i,vis);
            if (temp > maxi)
                maxi = temp;
        }
        return maxi;
    }
};

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    Solution obj;
    vector<vector<int>> bombs = {{2, 1, 3}, {6, 1, 4}};
    obj.maximumDetonation(bombs);
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}