#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    bool judgeSquareSum(int c) {
        int i=0,j=sqrt(c);
        while(i<=j){
            long long a = i*1LL*i;
            long long b = j*1LL*j;
            long long sum = a + b;
            if(sum == c)
                return true;
            else if(sum < c)
                ++i;
            else --j;
        }
        return false;
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