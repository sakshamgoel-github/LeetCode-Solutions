#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int>ans(n,0);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>>mh;
        priority_queue<int, vector<int>,greater<int>>avlRooms;
        for(int i=0;i<n;++i) avlRooms.push(i);
        sort(meetings.begin(), meetings.end());

        for(vector<int>&x: meetings){
            int s = x[0];
            long long f = 1LL*x[1];

            while(!mh.empty() && mh.top().first <= s){
                int room = mh.top().second;
                mh.pop();
                avlRooms.push(room);
                } 
            if(!avlRooms.empty()){
                int room = avlRooms.top();
                avlRooms.pop();
                mh.push({f,room});
                ans[room]++;
            } else{
                int duration = f - s;
                f = 1LL*duration + 1LL*mh.top().first;
                int room = mh.top().second;
                mh.pop();
                mh.push({f,room});
                ans[room]++;
            }
        }

        int maxRoom=0;
        for(int i=1;i<n;++i){
            if(ans[i] > ans[maxRoom]){
                maxRoom = i;
            }
        }
        return maxRoom;
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