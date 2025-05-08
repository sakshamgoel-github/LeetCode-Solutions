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
        if (i < 0)
            return false;
        else if (j < 0)
            return false;
        else if (i >= n)
            return false;
        else if (j >= m)
            return false;
        return true;
    }
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        minHeap.push({0, 0, 0, 1});
        while (!minHeap.empty())
        {
            vector<int> curr = minHeap.top();
            minHeap.pop();
            int i = curr[1]; int j = curr[2]; int time = curr[0];
            if(vis[i][j]) continue;
            vis[i][j] = true;
            if (i == n - 1 && j == m - 1)
                return time;

            for (auto d : dir)
            {
                int ni = d.first + i;
                int nj = d.second + j;
                if (!isValid(ni, nj, n, m))
                    continue;
                if (vis[ni][nj])
                    continue;

                int moveCost = curr[3];
                int ti = max(time, moveTime[ni][nj]) + moveCost;
                minHeap.push({ti, ni, nj, moveCost%2+1});
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