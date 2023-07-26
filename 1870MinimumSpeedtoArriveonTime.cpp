#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int N = dist.size();
        int lo = 1,hi = 1e7;
        int mid,res=-1;
        while (lo <= hi)
        {
            mid = ((hi-lo)/2)+lo;
            double timeTaken = 0.0;
            for(int d:dist){
                timeTaken = ceil(timeTaken);
                timeTaken += (d*1.0/mid);
            }
            if(timeTaken <= hour) {res = mid, hi = mid-1;}
            else lo = mid+1;
        }
        return res;     
    }
};

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    vector<int> dist = {1, 1, 100000};
    double hour = 2.01;
    Solution obj;
    cout << obj.minSpeedOnTime(dist, hour);
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}