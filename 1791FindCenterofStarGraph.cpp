#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
    int n1 = edges[0][0];
    int n2 = edges[0][1];
    if(n1 == edges[1][0] || n1 == edges[1][1])
        return n1;
    else return n2;    
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