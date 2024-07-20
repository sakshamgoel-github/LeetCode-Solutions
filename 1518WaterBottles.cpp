#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    int ans = 0;
public:
    int solve(int full, int empty, int ex){
        if(full == 0)
            return 0;
        return (solve((full+empty)/ex,(full+empty)%ex,ex)+full);
    }
    int numWaterBottles(int numBottles, int numExchange) {
        return solve(numBottles, 0, numExchange);
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