#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long int lo = 1,mid,hi = 0;
        for(int b:batteries){
            hi += b*1LL;
        }
        hi /= n;
        while(lo < hi){
            mid = (hi+lo+1)/2;
            long long time=0;
            for(int t : batteries) time += min((long long)t,mid);

            if(mid*n <= time) lo = mid;
            else hi = mid-1;
        }
        return lo;
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