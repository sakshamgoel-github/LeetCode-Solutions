#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    vector<vector<bool>> graph;

public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        graph.resize(n, vector<bool>(n, false));
        vector<int> cnt(n);

        for (auto &road : roads)
        {
            graph[road[0]][road[1]] = true;
            graph[road[1]][road[0]] = true;
            ++cnt[road[0]];
            ++cnt[road[1]];
        }
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; j++)
            {
                int t = cnt[i] + cnt[j] - graph[i][j];
                if (t > res)
                    res = t;
            }
        }
        return res;
    }
};

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    Solution obj;
    vector<vector<int>> roads = {{0, 1}, {0, 3}, {1, 2}, {1, 3}, {3, 2}, {2, 0}};
    obj.maximalNetworkRank(4, roads);
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}