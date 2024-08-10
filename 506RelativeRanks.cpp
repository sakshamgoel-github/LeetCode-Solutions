#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int>>v;
        int n = score.size();
        for(int i=0;i<n;++i){
            v.push_back({score[i], i});
        }    
        sort(v.begin(), v.end());
        vector<string>ans(n);
        for(int i=0;i<n;++i){
            int ind = v[i].second;
            string value = "";
            if(i == (n-1))
                value = "Gold Medal";
            else if(i == (n-2))
                value = "Silver Medal";
            else if(i == (n-3))
                value = "Bronze Medal";
            else value = to_string(n-i);
            ans[ind] = value;
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