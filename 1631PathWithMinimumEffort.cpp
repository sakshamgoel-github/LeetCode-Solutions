#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    int row, col;
    vector<vector<int>> t;

public:
    bool isSafe(int i, int j)
    {
        if (i >= row || i < 0 || j >= col || j < 0)
            return false;
        return true;
    }
    int solve(int i, int j, vector<vector<int>> &heights)
    {
        if(!isSafe(i,j)){
            return INT_MAX;
        }
        int left = solve(i,j-1,heights);
        int right = solve(i,j+1,heights);
        int 
    }
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        this->row = heights.size();
        this->col = heights[0].size();
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