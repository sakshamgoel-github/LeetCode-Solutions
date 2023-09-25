#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        for (auto &x : prerequisites)
        {
            indegree[x[0]]++;
            adj[x[1]].push_back(x[0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (!indegree[i])
                q.push(i);
        }
        int cnt = 0;
        while (!q.empty())
        {
            int n = q.size();
            cnt += n;
            for (int i = 0; i < n; ++i)
            {
                int curr = q.front();
                q.pop();
                for (auto child : adj[curr])
                {
                    indegree[child]--;
                    if (!indegree[child])
                        q.push(child);
                }
            }
        }
        return cnt == numCourses;
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