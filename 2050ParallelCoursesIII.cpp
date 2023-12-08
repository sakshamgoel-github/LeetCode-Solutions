#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        vector<int> graph[n];
        vector<int> indegree(n, 0);

        for (int i = 0; i < relations.size(); i++)
        {
            relations[i][0] = relations[i][0] - 1;
            relations[i][1] = relations[i][1] - 1;
            indegree[relations[i][1]]++;
            graph[relations[i][0]].push_back(relations[i][1]);
        }
        vector<int> newTime = time;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            if (!indegree[i])
                q.push({i, newTime[i]});
        }
        int ans = 0;
        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();
            ans = max(ans, curr.second);
            for (int child : graph[curr.first])
            {
                --indegree[child];
                newTime[child] = max(newTime[child], time[child] + curr.second);
                if (!indegree[child])
                    q.push({child, newTime[child]});
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