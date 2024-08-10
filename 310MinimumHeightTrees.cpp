#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges){
        if(n == 1)
            return {0};
        vector<int>graph[n];
        vector<int>indegree(n,0);
        for(auto e: edges){
            indegree[e[1]]++;
            indegree[e[0]]++;
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }    
        queue<int>q;
        for(int i=0;i<n;++i){
            if(indegree[i] == 1){
                q.push(i);
            }
        }
        while(n > 2){
            int l = q.size();
            n -= l;
            while(l--){
                int node = q.front();
                q.pop();
                for(int child: graph[node]){
                    indegree[child]--;
                    if(indegree[child] == 1)
                        q.push(child);
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
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