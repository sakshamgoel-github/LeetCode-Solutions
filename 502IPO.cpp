#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        vector<pair<int, int>> v;
        int n = profits.size();
        for (int i = 0; i < n; ++i) {
            v.push_back({capital[i], profits[i]});
        }
        sort(v.begin(), v.end());
        priority_queue<int> mh;
        int i = 0;
        while (k != 0 && i < n) {
            if (v[i].first <= w) {
                mh.push(v[i].second);
                ++i;
            } else {
                if(mh.size() > 0){
                auto curr = mh.top();
                mh.pop();
                w += curr;
                }
                --k;
            }
        }
        while (k != 0 && mh.size() > 0) {
            w += mh.top();
            mh.pop();
            --k;
        }
        return w;
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