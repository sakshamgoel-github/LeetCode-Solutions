#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    int N;
    vector<vector<int>>t;
public:
    int solve(int ind, int k, vector<vector<int>>& events){
        if(ind == N || k == 0)
            return 0;

        if(t[ind][k] != -1)
            return t[ind][k];
        
        int not_take = solve(ind + 1, k, events);
        int lo = ind + 1, hi = N-1;
        int j = N;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(events[mid][0] > events[ind][1]){
                hi = mid - 1;
                j = mid;
            } else {
                lo = mid + 1;
            }
        }
        int take = events[ind][2] + solve(j,k-1,events);
        int ans = max(take, not_take);
        return t[ind][k] = ans;
    }

    int maxValue(vector<vector<int>>& events, int k) {
        N = events.size();
        t.resize(N+1, vector<int>(k+1,-1));
        sort(events.begin(), events.end());
        return solve(0,k,events);
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