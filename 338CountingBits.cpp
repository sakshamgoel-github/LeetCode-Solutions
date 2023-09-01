#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    vector<int> countBits(int n) {
        if(!n)
        return {0};
        vector<int>arr(n+1);
        for (int i = 1; i <= n; i++)
        {
            if(i % 2) arr[i] = arr[i/2]+1;
            else arr[i] = arr[i/2];
        }
        return arr;
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