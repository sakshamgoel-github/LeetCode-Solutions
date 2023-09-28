#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>ans(V,INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> q;
        ans[S] = 0;
        q.push({0,S});
        while(!q.empty()){
            int dis = q.top().first;
            int curr = q.top().second;
            q.pop();
            for(auto x: adj[curr]){
                int node = x[0];
                int wt = x[1];
                if(ans[node] > (wt + dis))
                {ans[node] = dis+wt; q.push({dis+wt,node});}
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