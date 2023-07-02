#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int numNodes = graph.size();
        vector<int> colour(numNodes, -1);
        vector<bool> visited(numNodes, false);
        queue<int> q;
        for (int i = 0; i < numNodes; i++)
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
                int clr = 0;
                colour[i] = clr;
                while (!q.empty())
                {
                    int currNode = q.front();
                    clr = colour[currNode];
                    q.pop();
                    for (auto child : graph[currNode])
                    {
                        if (colour[child] == colour[currNode])
                            return false;

                        if (!visited[child])
                        {
                            colour[child] = 1 - clr;
                            q.push(child);
                            visited[child] = true;
                        }
                    }
                }
            }
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