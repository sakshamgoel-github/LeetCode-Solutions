#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>ump;
        int maxScore = 0;
        for(int &x:nums){
            ump[x]++;
            if(ump[x] > maxScore)
                maxScore = ump[x];
        }   
        int cnt = 0;       
        for(auto x: ump){
            if(x.second == maxScore)
            ++cnt;
        }
        return cnt * maxScore;
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