#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways = 0;
        int LIMIT = min(n,limit);
        for(int i=0;i<=LIMIT;++i){
            int N = n - i;
            int mini = max(0,N - LIMIT);
            int maxi = min(N,LIMIT);
            if(mini <= maxi)
            ways = ways + (maxi - (mini) + 1)*1LL;
        }      
        return ways;
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