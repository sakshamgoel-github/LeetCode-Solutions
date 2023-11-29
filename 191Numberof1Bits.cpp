#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;

        // T.C = O(K)
        // K -> number of set bits in number
        
        while(n != 0){
            ++ans;
            n &= (n-1);
        }

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