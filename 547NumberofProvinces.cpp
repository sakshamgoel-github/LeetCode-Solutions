#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class DSU
{
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n)
    {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = find(parent[u]);
    }
    void Union(int u, int v)
    {
        int root_u = find(u);
        int root_v = find(v);

        if (root_u != root_v)
        {
            if (size[root_u] > size[root_v])
            {
                parent[root_v] = root_u;
                size[root_u] += size[root_v];
            }
            else
            {
                parent[root_u] = root_v;
                size[root_v] += size[root_u];
            }
        }
    }
    int disJointSets()
    {
        int ans = 0;
        for (int i = 0; i < parent.size(); i++)
        {
            if (find(i) == i)
                ++ans;
        }
        return ans;
    }
};

class Solution
{

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        DSU ds(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                if (isConnected[i][j])
                    ds.Union(i, j);
            }
        }
        return ds.disJointSets();
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