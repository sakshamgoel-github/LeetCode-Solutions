#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        pair<int,int>p;
        p.first = points[0][0];
        p.second = points[0][1];
        int cnt = 1;
        int n = points.size();
        for (int i = 1; i < n; i++)
        {
            if(points[i][0] <= p.second){
                p.first = max(p.first,points[i][0]);
                p.second = min(p.second,points[i][1]);
            }
            else{
                p.first = points[i][0];
                p.second = points[i][1];
                ++cnt;
            }
        }
        return cnt;
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