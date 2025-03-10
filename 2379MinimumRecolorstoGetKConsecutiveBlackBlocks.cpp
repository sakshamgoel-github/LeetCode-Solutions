#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int n = blocks.length();
            int i=0, j=0; 
            int ans = 101;
            int t = 0;
            while(j < k){
                if(blocks[j] == 'W') ++t;
                ++j;
            }    
            ans = t;
            while(j < n){
                if(blocks[i++] == 'W')
                    --t;
                if(blocks[j++] == 'W')
                    ++t;
                ans = min(ans, t);
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