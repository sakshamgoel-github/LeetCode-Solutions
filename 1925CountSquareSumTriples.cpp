#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for (int i = 2; i < n; ++i)
        {
            for (int j = i+1; j < n; ++j)
            {
                for (int k = j+1; k <= n; ++k)
                {
                    int sum = (i*i) + (j*j);
                    if(sum == (k*k))
                        ans += 2;
                }                
            }            
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
    Solution obj;
    cout<<obj.countTriples(10);
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}