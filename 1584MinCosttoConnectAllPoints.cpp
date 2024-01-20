#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class DSU
{
private:
    vector<int> size;
    vector<int> parent;
public:
    DSU(int n)
    {
        size.resize(n, 1);  // Initialize sizes to 1
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;   // Initialize parents to themselves
        }
    }
    int find(int u){
        if(parent[u] == u)
        return u;
        return parent[u] = find(parent[u]); //path compression
    }
    void Union(int u, int v){ //union by size
        int ultParent_u = find(u);
        int ultParent_v = find(v);

        if(ultParent_u != ultParent_v){
            if(size[ultParent_u] > size[ultParent_v]){
                parent[ultParent_v] = ultParent_u;
                size[ultParent_u] += size[ultParent_v];
            }
            else {
                parent[ultParent_u] = ultParent_v;
                size[ultParent_v] += size[ultParent_u];
            }
        }
    }

};

class Solution
{
    vector<vector<int>> edges;

public:
    int kruskal(int n){
        int mst_wt = 0;
        sort(edges.begin(),edges.end());

        DSU obj(n);

        for (int i = 0; i < edges.size(); i++)
        {
            if(obj.find(edges[i][1])!=obj.find(edges[i][2])){
                mst_wt += edges[i][0];
                obj.Union(edges[i][1],edges[i][2]);
            }   
        }
        
        return mst_wt;
    }
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        for (int i = 0; i < n; i++)
        {
            int x1 = points[i][0];
            {
                int y1 = points[i][1];
                for (int j = i + 1; j < n; j++)
                {
                    int x2 = points[j][0];
                    int y2 = points[j][1];

                    int weight = abs(x1 - x2) + abs(y1 - y2);
                    edges.push_back({weight,i,j});
                }
            }
        }
       return kruskal(n);
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