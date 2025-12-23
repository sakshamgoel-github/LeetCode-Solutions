#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.length();
        int p = 0, s = 0, ans = 1, MOD = 1e9+7, totalS = 0;
        int i=0, j = n-1;
        while (i < n)
        {
            if(corridor[i] == 'S')
                break;
            ++i;
        }
        while (j >= 0)
        {
            if(corridor[j] == 'S')
                break;
            --j;
        }
        while (i <= j)
        {
            if(corridor[i] == 'P' && s == 0)
                ++p;
            else if (corridor[i] == 'S'){
                ++s;
                ++totalS;
                if(s == 2){
                    ans = (ans * 1LL * (p+1))%MOD;
                    s = 0;
                    p=0;
                }
            }
            ++i;
        }
        if((totalS & 1) || totalS == 0) return 0;
        return ans;             
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