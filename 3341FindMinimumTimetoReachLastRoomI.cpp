#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

    class Solution
    {
    public:
        bool isValid(int i, int j, int n, int m)
        {
            return i >= 0 && i < n && j >= 0 && j < m;
        }
    
        int minTimeToReach(vector<vector<int>> &moveTime)
        {
            int n = moveTime.size();
            int m = moveTime[0].size();
            vector<vector<bool>> vis(n, vector<bool>(m, false));
            priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
    
            minHeap.push({0, 0, 0});
            while (!minHeap.empty())
            {
                auto curr = minHeap.top();
                minHeap.pop();
                int time = curr[0], i = curr[1], j = curr[2];
    
                if (vis[i][j])
                    continue; 
                vis[i][j] = true;
                
                if (i == n - 1 && j == m - 1)
                    return time;
    
                vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                for (auto &dir : dirs)
                {
                    int ni = i + dir.first, nj = j + dir.second;
                    if (isValid(ni, nj, n, m) && !vis[ni][nj])
                    {
                        int newTime = max(time,moveTime[ni][nj])+1;
                        minHeap.push({newTime, ni, nj});
                    }
                }
            }
            return -1;
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