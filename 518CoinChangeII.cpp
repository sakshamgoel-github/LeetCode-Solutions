#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    vector<vector<int>>t;
public:
    int solve(int i, int amt, int &amount, vector<int>& coins, int n){
        if (amt == amount){
            return 1;
        }
        if ((amt > amount) || (i >= n))
        return 0;
        if(t[i][amt] != -1)
        return t[i][amt];
        
        int choice1 = solve(i, amt+coins[i],amount, coins, n);
        int choice2 = solve(i+1, amt,amount, coins, n);

        return t[i][amt] = (choice1 + choice2);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        t.resize(n+1, vector<int>(amount+1,-1));
        return solve(0,0,amount, coins, n);
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