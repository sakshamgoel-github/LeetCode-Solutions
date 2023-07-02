#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    int root;
    vector<vector<int>> graph;
    int dfs(int node,vector<int>&informTime){
        int time = 0;
        for(auto child:graph[node]){
            int t = dfs(child,informTime);
            time = max(t,time);
        }
        return time + informTime[node];
    }
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        graph.resize(n);
        for (int i = 0; i < n; i++)
        {
            if (manager[i] != -1)
                graph[manager[i]].push_back(i);
        }
        return dfs(headID,informTime);
    }
};

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
vector<int>manager={5,9,6,10,-1,8,9,1,9,3,4};
vector<int>informTime = {0,213,0,253,686,170,975,0,261,309,337};
int n =11;
int headID = 4;

Solution obj;
obj.numOfMinutes(n,headID,manager,informTime);
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}