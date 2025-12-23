#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int>ump;
        for(auto &x: points){
            ump[x[1]]++;
        }
        vector<long long>v;
        for(auto &x: ump){
            long long t = (x.second*1LL*(x.second-1))/(2LL);
            if(t)
            v.push_back(t);
        }
        int n = v.size();
        long long sum = 0;
        long long ans = 0;
        long long MOD = 1e9+7;
        for (int i = n-2; i >=0 ; --i)
        {
            sum += v[i+1];
            ans = (ans + v[i]*sum)%MOD;
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