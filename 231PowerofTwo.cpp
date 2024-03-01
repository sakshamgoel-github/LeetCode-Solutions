#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if( n < 0) return false;
        int cnt = 0;
        for (int i = 0; i < 32; i++)
        {
            if(n & 1) ++cnt;
            n = n>>1;
        }
        return cnt == 1;
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