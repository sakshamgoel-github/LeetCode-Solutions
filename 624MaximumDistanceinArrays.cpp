#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int findMini(vector<pair<int,int>>&v, int skip){
        int mini = (skip == 0 ? 1 : 0);
        for(int i=0;i<v.size();++i){
            if(i == skip)
                continue;
            if(v[i].first < v[mini].first)
                mini = i;
        }
        return mini;
    }
    int findMaxi(vector<pair<int,int>>&v, int skip){
        int maxi = (skip == 0 ? 1 : 0);
        for(int i=0;i<v.size();++i){
            if(i == skip)
                continue;
            if(v[i].second > v[maxi].second)
                maxi = i;
        }
        return maxi;
    }
    int maxDistance(vector<vector<int>>& arrays) {
        int m = arrays.size();
        vector<pair<int,int>>t(m);
        for(int i=0;i<m;++i){
            int mini = INT_MAX;
            int maxi = INT_MIN;
            for(int x: arrays[i]){
                if(x < mini)
                    mini = x;
                if(x > maxi)
                    maxi = x;
            }
            t[i] = {mini, maxi};
        }    
        int ans = 0;
        int a = findMini(t,-1);
        int b = findMaxi(t,a);
        ans = abs(t[b].second - t[a].first);
        cout<<a<<" "<<b;
        b = findMaxi(t,-1);
        a = findMini(t,b);
        ans = max(ans,abs(t[b].second - t[a].first));
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