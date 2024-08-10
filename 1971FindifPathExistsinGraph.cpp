#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    bool dfs(int node, vector<int>graph[], vector<int>&vis,int destination){
        vis[node] = true;
        if(node == destination)
            return true;
        for(int child: graph[node]){
            if(!vis[child]){
               bool t = dfs(child, graph, vis, destination);
               if(t)
                return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>graph[n];
        vector<int>vis(n,false);
        for(vector<int>e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        return dfs(source, graph, vis, destination);
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