#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<long long int>v(n-1);
        for (int i = 0; i < n-1; i++)
        {
            v[i] = 1LL*weights[i] + weights[i+1]*1LL;
        }
        sort(v.begin(),v.end());
        long long ans = 0;
        for (int i = 0; i < k-1; i++)
        {
            ans += v[n-2-i];
            ans -= v[i];
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