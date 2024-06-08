#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize)
            return false;
        map<int,int>mp;
        for(int x: hand){
            ++mp[x];
        }
       for(int i=0;i<n;i = i + groupSize){
            int k = groupSize;
            int curr = mp.begin()->first;
            for(int k=0;k<groupSize;++k){
                if(mp.find(curr) == mp.end())
                    return false;
                mp[curr]--;
                if(mp[curr] == 0)
                    mp.erase(curr);
                ++curr;
            }
        }
        return true;
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