#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

 
class Solution {
public:
    int equalPairs(vector<vector<int> >& grid) {
        map<vector<int>, int> hashmap;
        int ans = 0;
        int row = grid.size();
        int col = grid[0].size();
        for (int i=0; i<row; i++) {
            hashmap[grid[i]]++;
        }
        for (int j=0; j<col; j++) {
            vector<int> curr;
            for (int i=0; i<row; i++) {
                curr.emplace_back(grid[i][j]);
            }
            ans += hashmap[curr];
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