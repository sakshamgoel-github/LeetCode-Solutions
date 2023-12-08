#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1) return 0;
        if(n == 2){
            if(k == 1) return 0;
            if(k == 2) return 1;
        }
        int tot = pow(2,n-1);
        if(k <= tot/2) return kthGrammar(n-1,k);
        if(n%2 == 0) return !kthGrammar(n-1,tot-k+1);
        return kthGrammar(n-1,tot-k+1);
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