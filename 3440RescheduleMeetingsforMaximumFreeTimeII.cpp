#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int>rightMax;
        rightMax.push_back(eventTime - endTime.back());
        for(int i = startTime.size()-2;i>=0;--i){
            int curr = startTime[i+1] - endTime[i];
            curr = max(curr, rightMax.back());
            rightMax.push_back(curr);
        }    
        reverse(rightMax.begin(), rightMax.end());

        vector<int>leftMax;
        leftMax.push_back(startTime[0]);
        for(int i=1;i<startTime.size();++i){
            int curr = startTime[i] - endTime[i-1];
            curr = max(curr, leftMax.back());
            leftMax.push_back(curr);
        }

        int ans = 0;
        for(int i=0;i<startTime.size();++i){
            int rmax, lmax, duration, rightGap, leftGap,curr;
            lmax = (i == 0) ? 0 : leftMax[i-1];
            rmax = (i == startTime.size()-1) ? 0 : rightMax[i+1];
            duration = endTime[i] - startTime[i];
            rightGap = (i == startTime.size()-1) ? eventTime - endTime.back() : startTime[i+1] - endTime[i];
            leftGap = (i == 0) ? startTime[0] : startTime[i] - endTime[i-1];

            if(lmax >= duration || rmax >= duration){
                curr = duration + rightGap + leftGap;
            } else {
                curr = rightGap + leftGap;
            }

            ans = ans > curr ? ans : curr;
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