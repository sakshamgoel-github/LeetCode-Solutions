#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker){
        vector<pair<int,int>>v;
        int n = difficulty.size();
        for(int i=0;i<n;++i){
            v.push_back({profit[i],difficulty[i]});
        }
        sort(v.begin(), v.end());
        sort(worker.begin(), worker.end());
        int ans = 0;
        int m = worker.size();
        for(int i=m-1,j=n-1;i>=0;--i){
            while(j >= 0){
                if(v[j].second <= worker[i]){
                    ans += v[j].first;
                    break;
                }
                --j;
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