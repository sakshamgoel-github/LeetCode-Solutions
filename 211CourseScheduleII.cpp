#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        vector<int>indegree(numCourses,0);
        for(auto &x : prerequisites){
            int parent = x[1];
            int child = x[0];
            adj[parent].push_back(child);
            indegree[child]++;
        }
        queue<int>q;
        for (int i = 0; i < numCourses; ++i)
        {
            if(!indegree[i])
            q.push(i);
        }
        vector<int>order;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto child:adj[node]){
                indegree[child]--;
                if(!indegree[child])
                q.push(child);
            }
            order.push_back(node);
        }
        if(order.size() == numCourses)
        return order;
        order.clear();
        return order;        
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