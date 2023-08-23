#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

long  long int myPow(int n, int m){
    long long int ans = 1;
    while (m)
    {
        if((m%2)){
            ans *= n;
            --m;
        }
        n*=n;
        m/=2;
    }
    return ans;
}

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}