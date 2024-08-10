#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int getSoldiers(vector<vector<int>>&mat, int row){
        int lo = 0, hi = mat[0].size()-1;
        while (lo <= hi)
        {
            int mid = (lo+hi)/2;
            if(mat[row][mid] == 1) lo = mid+1;
            else hi = mid-1;
        }
        return lo;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>>mh;
        for (int i = 0; i < mat.size(); i++)
        {
            mh.push({getSoldiers(mat,i),i});
            if(mh.size()>k) mh.pop();
        }
        vector<int>ans;
        while (!mh.empty())
        {
            ans.push_back(mh.top().second);
            mh.pop();
        }
        reverse(ans.begin(),ans.end());
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