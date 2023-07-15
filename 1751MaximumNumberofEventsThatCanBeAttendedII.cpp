#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    int N;
public:
    int solve(int ind, int k,vector<vector<int>>& events,vector<vector<int>>&t){
        if( ind>=N || !k)
        return 0;

        if(t[ind][k] != -1)
        return t[ind][k];

        int i=ind+1;
        for(;i<N;++i){
            if(events[ind][1] < events[i][0])
            break;
        }

        int ans1 = events[ind][2] + solve(i,k-1,events,t);
        int ans2 = solve(ind+1,k,events,t);

        return t[ind][k] = max(ans1,ans2);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        this -> N = events.size();
        sort(events.begin(),events.end());
        vector<vector<int>>t(N+1,vector<int>(k+1,-1));
        return solve(0,k,events,t);
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