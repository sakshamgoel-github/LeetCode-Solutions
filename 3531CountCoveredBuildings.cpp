#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,pair<int,int>>umpx;
        unordered_map<int,pair<int,int>>umpy;
        
        for (int i = 0; i < buildings.size(); i++)
        {
            int x = buildings[i][0];
            int y = buildings[i][1];

            if(umpx.find(x) == umpx.end())
                umpx[x] = {y,y};
            else {
                umpx[x].first = max(umpx[x].first, y);
                umpx[x].second = min(umpx[x].second, y);
            }

            if(umpy.find(y) == umpy.end())
                umpy[y] = {x,x};
            else {
                umpy[y].first = max(umpy[y].first, x);
                umpy[y].second = min(umpy[y].second, x);
            }

        }

        int ans = 0;
        for (int i = 0; i < buildings.size(); i++)
        {
            int x = buildings[i][0];
            int y = buildings[i][1];

            int x1 = umpy[y].second;
            int x2 = umpy[y].first;
            int y1 = umpx[x].first;
            int y2 = umpx[x].second;

            if(y1 <= y) continue;
            if(y2 >= y) continue;
            if(x2 <= x) continue;
            if(x1 >= x) continue;
            ++ans;
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