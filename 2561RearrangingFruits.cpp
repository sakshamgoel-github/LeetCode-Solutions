#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size();
        int mini = basket1[0];
        if(basket2.size() != n)
            return -1;
        
        unordered_map<int,int>ump;
        vector<int>v;
        for(int &x: basket1){
            if(mini > x)
                mini = x;
            ++ump[x];
        }
        for(int &x: basket2){
            if(mini > x)
                mini = x;
            --ump[x];
        }
        for(auto &x: ump){
            x.second = abs(x.second);
            if(x.second & 1)
                return -1;
            int key = x.first;
            int freq = x.second;

            for(int i=0;i<freq/2;++i)
                v.push_back(key);
        }
        sort(v.begin(), v.end());
        long long ans = 0;
        for(int i=0;i<v.size()/2;++i){
            long long t = 1LL*v[i] < 2*1LL*mini ? 1LL*v[i] : 2*1LL*mini; 
            ans = ans + t;
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