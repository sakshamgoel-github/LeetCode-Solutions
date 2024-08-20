#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>t(n+1);
        int p2,p3,p5;
        p2=p3=p5=1;
        t[1] = 1;
        for(int i=2;i<=n;++i){
            int p2Num = t[p2]*2;
            int p3Num = t[p3]*3;
            int p5Num = t[p5]*5;

            t[i] = min({p2Num, p3Num, p5Num});
            
            if(t[i] == p2Num) ++p2;
            if(t[i] == p3Num) ++p3;
            if(t[i] == p5Num) ++p5;
        }
        return t[n];
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