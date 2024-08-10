#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0;
        bool oddCount = 0;
        int mini = INT_MAX;
        for(int x: nums){
            int t = x ^ k;
            if(t > x){
                oddCount=!oddCount;
                sum += 1LL*t;
            }
            else sum += 1LL*x;
            mini = min(mini,abs(t - x));
        }
        if(oddCount)
            sum -= 1LL*mini;
        return sum;
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