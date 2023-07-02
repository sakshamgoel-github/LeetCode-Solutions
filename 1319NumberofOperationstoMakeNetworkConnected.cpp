#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    private:
    void dfs(int node,vector<bool>&vis,vector<int>adj[]){
        vis[node] = true;
        for(auto child:adj[node]){
            if(!vis[child])
            dfs(child,vis,adj);
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
        return -1;
        int cc = 0;
        vector<int>adj[n];
        for(auto &x:connections){
            int node1 = x[0];
            int node2 = x[1];
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }
        vector<bool>vis(n,false);
        for (int i = 0; i < n; i++)
        {
            if(!vis[i]){
                ++cc;
                dfs(i,vis,adj);
            }
        }
        return cc - 1;
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