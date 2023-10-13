#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    vector<vector<double>>t;
public:
    double solve(int a, int b){

        if(a<=0 && b<=0)
            return 0.5;
        else if (a<=0)
        return 1.0;

        else if (b<=0)
        return 0.0;
        
        if(t[a][b] != -1.0)
        return t[a][b];

        double ans = 0.0;
        ans += solve(a-100,b);
        ans += solve(a-75,b-25);
        ans += solve(a-50,b-50);
        ans += solve(a-25,b-75);

        return t[a][b] = ans*0.25;        
    }
    double soupServings(int n) {
        if(n>=4000)
        return 1.0;
        t.resize(n+1,vector<double>(n+1,-1.0)); 
        return solve(n,n);
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