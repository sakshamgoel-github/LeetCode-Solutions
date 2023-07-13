#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    vector<vector<int>> graph;

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        graph.resize(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto &x : prerequisites)
        {
            graph[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        queue<int> q;
        vector<bool> vis(numCourses, false);
        for (int i = 0; i < numCourses; ++i)
        {
            if (!indegree[i])
            {
                q.push(i);
                vis[i] = true;
            }
        }
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (auto child : graph[curr])
            {
                if (!vis[child])
                {
                    --indegree[child];
                    if (!indegree[child])
                    {
                        q.push(child);
                        vis[child] = true;
                    }
                }
            }
        }
        for (int i = 0; i < numCourses; ++i)
        {
            if (indegree[i])
                return false;
        }
        return true;
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