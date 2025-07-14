#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    int t[1001][1001];
    int solve(int curr, int clip, int n){
        if(curr == n)
            return 0;
        else if(curr > n)
            return 1e6;
        if(t[curr][clip] != -1)
            return t[curr][clip];
        int choice1 = 2 + solve(curr*2, curr, n);
        int choice2 = 1 + solve(curr+clip, clip, n);
        int mini = min(choice1, choice2);
        return t[curr][clip] = mini;
    }
public:
    int minSteps(int n) {
        if(n == 1)
            return 0;
        memset(t, -1, sizeof(t));
        return 1 + solve(1,1,n);
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
