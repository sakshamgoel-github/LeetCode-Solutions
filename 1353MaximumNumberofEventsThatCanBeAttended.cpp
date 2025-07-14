#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        priority_queue<int,vector<int>,greater<int>>mh;
        sort(events.begin(), events.end());
        int i=0;
        int ans = 0, day = 1;
        while(i < n || !mh.empty()){
            while(i < n && events[i][0] == day){
                mh.push(events[i][1]);
                ++i;
            }
            if(!mh.empty() && mh.top() >= day && mh.pop())
                ++ans;
            ++day;
            while(!mh.empty() && mh.top() < day)
                mh.pop();
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