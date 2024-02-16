#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    vector<int>t;
public:
    Solution(){
        t.resize(1e4+1,-1);
    }
    int numSquares(int n) {
        if(n == 0)
        return 0;
        if(t[n] != -1)
        return t[n];
        int ans = INT_MAX;
        for (int i = 1; i*i <= n; i++)
        {
            int t = numSquares(n - i*i) + 1;
            ans = min(t,ans);
        }
        return t[n] = ans;        
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