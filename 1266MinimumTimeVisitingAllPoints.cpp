#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    int shortestDis(int x1, int y1, int x2, int y2)
    {
        int dx = abs(x1 - x2);
        int dy = abs(y1 - y2);
        int ans = min(dx, dy) + abs(dx - dy);
        return ans;
    }

public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        int time = 0;
        int x1 = points[0][0];
        int y1 = points[0][1];
        for (int i = 1; i < n; i++)
        {
            int x2 = points[i][0];
            int y2 = points[i][1];
            int t = shortestDis(x1, y1, x2, y2);
            time += t;
            x1 = x2;
            y1 = y2;
        }
        return time;
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