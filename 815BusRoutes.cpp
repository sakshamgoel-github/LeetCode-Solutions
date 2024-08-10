#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        if (source == target)
            return 0;
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < routes.size(); ++i)
        {
            for (auto stops : routes[i])
            {
                adj[stops].push_back(i);
            }
        }
        queue<int> q;
        vector<bool> vis(routes.size(), false);
        for (int x : adj[source])
        {
            q.push(x);
            vis[x] = true;
        }
        int cnt = 1;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int route = q.front();
                q.pop();
                for (int stop : routes[route])
                {
                    if (stop == target)
                        return cnt;
                    for (int r : adj[stop])
                    {
                        if (!vis[r])
                        {
                            q.push(r);
                            vis[r] = true;
                        }
                    }
                }
            }
            ++cnt;
        }
        return -1;
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