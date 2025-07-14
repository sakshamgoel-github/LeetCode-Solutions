#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    bool check(vector<int>&ranks, int cars, long long time){
        long long c = 0;
        for (int i = 0; i < ranks.size(); i++)
        {
            c += sqrt(time/(1LL*ranks[i]));
        }
        return (c>=(1LL*cars));
    }
    public:
        long long repairCars(vector<int>& ranks, int cars) {
            long long lo = 1, hi = 1e14, mid;
            long long ans;
            while (lo <= hi)
            {
                mid = (lo+hi)/2;
                if(check(ranks, cars, mid)){
                    ans=mid;
                    hi=mid-1;
                }
                else lo=mid+1;
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