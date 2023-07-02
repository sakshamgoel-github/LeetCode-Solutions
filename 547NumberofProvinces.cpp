#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    vector<int>vis;
    int n;
    void dfs(int node, vector<vector<int> >&isConnected){
        vis[node] = true;
        for (int i = 0; i < n; i++)
        {
            if (isConnected[node][i] && !vis[i]){
                dfs(i,isConnected);
            }
        }        
    }
public:
    int findCircleNum(vector<vector<int> >&isConnected) {
        n = isConnected.size();
        vis.resize(n,false);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if(!vis[i]){
                ++ans;
                dfs(i,isConnected);
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

    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}