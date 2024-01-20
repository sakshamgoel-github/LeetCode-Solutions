#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
private:
int change;
vector<bool>vis;
public:
    Solution(){
        change = 0;
    }
    void dfs(int node, vector<int>adj[]){
        vis[node] = true;
        for(auto child:adj[node]){
            if(!vis[abs(child)]){
                change+=child<0;
                dfs(abs(child),adj);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto &x:connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(-x[0]);
        }          
        vis.resize(n,false);
        dfs(0,adj);
        return change;
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