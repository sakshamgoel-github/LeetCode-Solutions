#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    vector<int> prices;
    int fee;
    int N;

public:
    int solve(int i, vector<vector<int>>&t, bool bought = false){
        if (i >= N)
        return 0;

        int profit = 0;

        if(!bought){
            int ans1 = solve(i+1, t, !bought) - prices[i];
            int ans2 = solve(i+1,t,bought);

            profit = max(profit, max(ans1, ans2));
        }
        else {
            int ans1 = solve(i+1,t,!bought) + prices[i] - fee;
            int ans2 = solve(i+1,t,bought);

            profit = max(profit, max(ans1, ans2));
        }

        return t[i][bought] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        this->N = prices.size();
        this->fee = fee;
        this->prices = prices;
        vector<vector<int>>t(N + 1, vector<int>(2, -1));
        return solve(0,t);
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