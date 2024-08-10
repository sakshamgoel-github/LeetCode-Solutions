#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {    
private:
    int dp(int ind, int time, vector<int>&satisfaction,int n,vector<vector<int>>&t){
        if(ind>=n)
        return 0;
        if(t[ind][time]!=-1)
        return t[ind][time];
        int ans1 = (time * satisfaction[ind]) + dp(ind+1,time+1,satisfaction,n,t);
        int ans2 = dp(ind+1,time,satisfaction,n,t);
        t[ind][time] = max(ans1,ans2);
        return t[ind][time];
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();    
        vector<vector<int>>t(n + 1, vector<int>(n + 2, -1));
        int ans = dp(0,1,satisfaction,n,t);
        return ans;
    }
};

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    Solution obj;
    vector<int>satisfaction = {-1,-8,0,5,-9};
    cout<<obj.maxSatisfaction(satisfaction);
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}