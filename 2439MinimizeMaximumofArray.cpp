#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution {
public:
    int minimizeArrayValue(vector<int>& A) {
       int n = A.size();
       int ans = 0;
       int sum = 0;
       for (int i = 0; i < n; ++i)
       {
        sum+=A[i];
        ans = max(ans,((sum+i)/(i+1)));
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