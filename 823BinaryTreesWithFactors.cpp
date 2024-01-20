#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int MOD = 1e9+7;
        sort(arr.begin(),arr.end());
        int n = arr.size();
        unordered_map<int,int>ump;
        for(int x: arr){
            ump[x] = 1;
        }    
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if(arr[i] % arr[j] == 0){
                    if(ump.find(arr[i]/arr[j])!=ump.end()){
                        int left = arr[j];
                        int right = arr[i]/arr[j];
                        ump[arr[i]] = (ump[arr[i]] + (ump[left]*1LL*ump[right])%MOD)%MOD;
                    }
                }
            }            
        }
        long long int ans = 0;
        for(auto x: ump){
            ans += x.second*1LL;
            ans %= MOD;
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