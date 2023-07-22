#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    int N;
    unordered_map<string,double>t;
    vector<pair<int, int>> dir;
public:
    Solution() {
        dir.push_back({-1, 2});
        dir.push_back({1, 2});
        dir.push_back({2, 1});
        dir.push_back({2, -1});
        dir.push_back({1, -2});
        dir.push_back({-1, -2});
        dir.push_back({-2, -1});
        dir.push_back({-2, 1});
    }

    double solve(int i, int j, int k) {
        if (i >= N || i < 0 || j >= N || j < 0) {
            return 0; 
        }
        if (k == 0) {
            return 1.0; 
        }
        string s = to_string(i)+"_"+to_string(j)+"_"+to_string(k);
        if (t.find(s) != t.end()) {
            return t[s];
        }

        double ans = 0;
        for (int d = 0; d < 8; ++d) {
            ans += solve(i + dir[d].first, j + dir[d].second, k - 1);
        }
        return t[s] = (ans / 8.0);
    }

    double knightProbability(int n, int k, int row, int column) {
        this->N = n;
        return solve(row, column, k);
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