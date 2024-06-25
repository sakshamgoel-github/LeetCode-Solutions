#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    bool solve(vector<int>&bloomDay, int m, int k, int day){
        int n = bloomDay.size();
        int tempK = k;
        for(int i=0;i<n;++i){
            if(day >= bloomDay[i]){
                --tempK;
                if(tempK == 0){
                    --m;
                    tempK = k;
                }
            }
            else{
                tempK = k;
            }
        }
        return m <= 0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans = -1;
        int lo = 1,hi = 1e9;
        while(lo <= hi){
            int mid = (hi-lo)/2+lo;
            bool t = solve(bloomDay,m,k,mid);
            if(t == true){
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid+1;
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