#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int>t(n);
        for(int i=0;i<n;++i){
            t[i] = ceil((float)dist[i]/speed[i]);
        }
        sort(t.begin(),t.end());
        int cnt = 1, timePassed = 1;
        for(int i=1;i<n;++i){
            if(t[i] - timePassed <= 0) return cnt;
            ++cnt;
            ++timePassed;
        }
        return cnt;
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