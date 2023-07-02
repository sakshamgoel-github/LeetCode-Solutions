#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        
        if(n == 2)
        return true;

        int deltaX1 = coordinates[0][0] - coordinates[1][0];
        int deltaY1 = coordinates[0][1] - coordinates[1][1];

        for(int i=2;i<n;++i){
        int deltaX2 = coordinates[0][0] - coordinates[i][0];
        int deltaY2 = coordinates[0][1] - coordinates[i][1];

        if(deltaY1 * deltaX2 != deltaY2 * deltaX1)
        return false;
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