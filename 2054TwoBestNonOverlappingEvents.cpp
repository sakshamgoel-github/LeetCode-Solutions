#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int BS(int ind, vector<vector<int>>& events){
        int lo = ind+1, hi = events.size()-1;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(events[mid][0] > events[ind][1]){
                hi = mid - 1;
            } else lo = mid + 1;
        }

        return lo;
    }
    int solve(int ind, int cnt,vector<vector<int>>&t, vector<vector<int>>& events){
        if(ind >= events.size() || cnt == 0)
            return 0;
        
        if(t[ind][cnt] != -1)
            return t[ind][cnt];

        int ch1 = solve(ind+1, cnt, t, events);
        int ch2 = events[ind][2] + solve(BS(ind, events), cnt-1, t, events);

        return (t[ind][cnt] = max(ch1, ch2));
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<vector<int>>t(events.size()+1, vector<int>(3, -1));
        sort(events.begin(), events.end());
        return solve(0,2,t,events);
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