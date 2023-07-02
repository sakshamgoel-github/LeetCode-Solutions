#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    int dfs(int node, vector<int>&edges, vector<bool>&vis){
        int size = 1;
        vis[node] = true;
        int child = edges[node];
        if(!vis[child])
        {
            size+=dfs(child,edges,vis);
        }
        return size;
    }
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int>indegree(n,0);
        for(auto &x:edges){
            if(x!=-1)
            ++indegree[x];
        }
        queue<int>q;
        for(int i = 0;i<n;++i){
            if(!indegree[i])
            q.push(i);
        }
        cout<<"\n";
        int order_size = 0;
        while (!q.empty())
        {
            ++order_size;
            int node = q.front();
            q.pop();
            int child = edges[node];
            if(child==-1)
            continue;
            --indegree[child];
            if(!indegree[child])
            q.push(child);
        }
        if(order_size == n)
        return -1;
        vector<bool>vis(n,false);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {   int temp = 0;
            if(indegree[i] && !vis[i])
            temp = dfs(i,edges,vis);
            if(temp>ans)
            ans = temp;
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
Solution obj;
vector<int>edges = {-1,-1,-1};
cout<<obj.longestCycle(edges);
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}