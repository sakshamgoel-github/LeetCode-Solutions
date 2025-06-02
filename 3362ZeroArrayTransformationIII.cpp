#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution{
public:
    bool comp(vector<int> &a, vector<int> &b){
        return ((a[1] - a[0]) < (b[1] - b[0]));
    }
    bool solve(int left, int right, vector<int> &nums, vector<vector<int>> &queries){
                
    }
    int maxRemoval(vector<int> &nums, vector<vector<int>> &queries){
        sort(queries.begin(),queries.end(),comp);

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