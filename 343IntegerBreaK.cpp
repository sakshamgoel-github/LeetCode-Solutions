#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    unordered_map<int,long long int>t;
public:
    int solve(int N){
        if(N <= 3) return N;
        if(t.find(N) != t.end()) return t[N];
        int ans = N;
        for(int i = 1;i < N -1;++i){
            ans = max(ans,solve(N - i) * i);
        }
        return t[N] = ans;
    }
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
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