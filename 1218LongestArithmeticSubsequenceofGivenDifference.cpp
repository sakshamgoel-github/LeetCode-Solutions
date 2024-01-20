#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int>ump;
        int n = arr.size();
        int res = 0;
        for(int i = 0; i < n;++i){
            ump[arr[i]] = ump[arr[i] - difference]+1;
            res = max(res,ump[arr[i]]);
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

    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}