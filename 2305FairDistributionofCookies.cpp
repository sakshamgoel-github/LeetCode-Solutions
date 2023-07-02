#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    int N;
    int k;
    vector<int>cookies;
public:
    int solve(int ind, vector<int>&children){
        if (ind >= N){
            int maxi = *max_element(children.begin(),children.end());
            return maxi;
        }
        int ans = INT_MAX - 1;
        for(int i=0;i<k;++i){
            children[i] += cookies[ind];
            int t = solve(ind+1,children);
            children[i] -= cookies[ind];
            if(t < ans)
            ans = t;
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        this -> cookies = cookies;
        this -> k = k;
        this -> N = cookies.size();

        vector<int>children(k,0);        

        return solve(0,children);
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