#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    public:
        int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
            int n = arr.size();
            int ans = 0;
            for(int k = 2; k < n; ++k){
                for(int j = 1;j < k; ++j){
                    if(abs(arr[j] - arr[k]) > b) continue;
                    for(int i = 0;i < j; ++i){
                        if((abs(arr[i] - arr[j]) <= a) && (abs(arr[i] - arr[k]) <= c))
                            ++ans;
                    }
                }
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