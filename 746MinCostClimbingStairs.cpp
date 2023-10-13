#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    vector<int>t;
public:
    int solve(int ind,vector<int>& cost){
        if(ind >= cost.size())
        return 0;
        if(t[ind] != -1) return t[ind];
        int choice1 = solve(ind+1, cost);
        int choice2 = solve(ind+2, cost);

        return t[ind] = min(choice1, choice2) + cost[ind];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        t.resize(cost.size(),-1);
        return min(solve(0,cost), solve(1, cost));
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