#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    double myPow(double x, int N) {
        double ans = 1;
        int n = abs(N);
        while(n>=1){
            if (n&1){ //odd
                ans *= x;
                n--;
            }
            n/=2;
            x=x*x;            
        }
        if (N<0)
        return 1.0/ans;
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