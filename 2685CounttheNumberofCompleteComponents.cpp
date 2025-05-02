#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

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
    int setSize(int u){
        int par = find(u);
        return size[par];
    }

};

class Solution {
    vector<int>indegree;
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        indegree.resize(n);
        DSU obj(n);
        int ans = 0;
        for(vector<int>&e: edges){
            indegree[e[0]]++;
            indegree[e[1]]++;
            obj.Union(e[0],e[1]);
        }
        unordered_map<int,vector<int>>ump;
        for(int i=0;i<n;++i){
            int par = obj.find(i);
            ump[par].push_back(i);
        }
        for(auto x: ump){
            int s = obj.setSize(x.first)-1;
            bool flag = true;
            for(auto y: ump[x.first]){
                if(indegree[y] != s){
                    flag = false; break;}
            }
            if(flag) ++ans;
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