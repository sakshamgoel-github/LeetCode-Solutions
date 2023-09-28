#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
  public:
    /*  
    *   Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int>ans(V,1e8);
        ans[S] = 0;

        for(int i=0;i<V-1;++i){
            for(auto &edge:edges){
                int n1 = edge[0];
                int n2 = edge[1];
                int wt = edge[2];
                if(ans[n2] > (ans[n1] + wt)) ans[n2] = ans[n1] + wt;
            }
        }
        for(auto &edge:edges){
                int n1 = edge[0];
                int n2 = edge[1];
                int wt = edge[2];
                if(ans[n2] > (ans[n1] + wt)) return {-1};
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