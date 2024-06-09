#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>ump;
        ump[0]=1;
        int sum = 0,result=0;
        for(int i=0;i<n;++i){
            sum += nums[i];
            int rem = sum%k;
            rem = rem < 0 ? rem+k:rem;
            if(ump.find(rem) != ump.end()){
                result += ump[rem];
            }
            ump[rem]++;
        }
        return result;
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