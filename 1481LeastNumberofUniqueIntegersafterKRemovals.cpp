#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int>ump;
        for (int i = 0; i < n; i++)
        {
            ump[arr[i]]++;
        }
        vector<int>bucket(n+1);
        for(auto &x: ump){
            bucket[x.second]++;
        }
        int ans = ump.size();
        for (int i = 1; i < n+1; i++)
        {            
            if(k/i == 0) return ans;
            int t = min(k/i,bucket[i]) ;
            ans -= t;
            k -= t*i;
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