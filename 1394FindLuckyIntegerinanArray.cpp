#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans = -1;
        int i = 0, j = 0, freq = 0;
        for (; j < arr.size(); ++j) {
            if (arr[j] == arr[i])
                ++freq;
            else{
                if(freq == arr[i] && arr[i] > ans)
                    ans = arr[i];
                i = j;    
                freq = 1;
            }
        }
        if(freq == arr[i] && arr[i] > ans)
                    ans = arr[i];
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