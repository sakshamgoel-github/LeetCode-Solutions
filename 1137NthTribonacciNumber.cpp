#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    vector<int>t;
public:
    int solve(int n){
        if(t[n] != -1)
            return t[n];
        t[n] = solve(n-1) + solve(n-2) + solve(n-3);
        return t[n];
    }
    int tribonacci(int n) {
        t.resize(38,-1);
        t[0] = 0;
        t[1] = 1;
        t[2] = 1;
        return solve(n);
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