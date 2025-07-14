#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int>freeTime;
        int ft = startTime[0];
        freeTime.push_back(ft);
        for(int i=1;i<startTime.size();++i){
            ft = startTime[i] - endTime[i-1];
            freeTime.push_back(ft);
        }
        ft = eventTime - endTime.back();
        freeTime.push_back(ft);
        
        int i=0,j=0,n=freeTime.size();
        int ans = 0, currSum = 0;
        while(j < n){
            currSum += freeTime[j];
            if(j-i+1 > k+1){
                currSum -= freeTime[i];
                ++i;
            }
            ++j;
            ans = max(ans,currSum);
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