#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    int n, m;
    vector<pair<int, int>> dir{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

public:
    pair<int, int> dfs(vector<vector<int>> &land, int i, int j)
    {
        if (i >= n || j >= m || i < 0 || j < 0)
            return {-1, -1};
        else if (land[i][j] == 0)
            return {-1, -1};
        land[i][j] = 0;
        pair<int, int> p = {i, j};
        for (int d = 0; d < 4; d++)
        {
            pair<int, int> t = dfs(land, i + dir[d].first, j + dir[d].second);
            if(t.first >= p.first && t.second>= p.second)
                p = t;
        }
        return p;
    }
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        n = land.size();
        m = land[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<n;++i){
            for (int j = 0; j < m; j++)
            {
                if(land[i][j] == 1){
                    vector<int>t{i,j};
                    pair<int,int>p = dfs(land,i,j);
                    t.push_back(p.first);
                    t.push_back(p.second);
                    ans.push_back(t);
                }
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