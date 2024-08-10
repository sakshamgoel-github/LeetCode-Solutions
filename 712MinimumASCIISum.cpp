#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    string s1, s2;
    int N, M;
    vector<vector<int>>t;
public:
    int solve(int i, int j){
        if(i >= N){
            int ans = 0;
            while( j<M ){
                ans += s2[j];
                ++j;
            }
            return ans;
        }
        else if (j >= M){
            int ans = 0;
            while( i<N ){
                ans += s1[i];
                ++i;
            }
            return ans;
        }
        
        if(t[i][j]!=-1)
        return t[i][j];

        if (s1[i] == s2[j])
        return t[i][j] = solve(i+1,j+1);

        int choice1 = solve(i+1,j) + s1[i];
        int choice2 = solve(i,j+1) + s2[j];

        return t[i][j] = min(choice1, choice2);
    }
    int minimumDeleteSum(string s1, string s2) {
        this -> s1 = s1;
        this -> s2 = s2;
        this -> N = s1.length();
        this -> M = s2.length();
        t.resize(N+1, vector<int>(M+1,-1));
        return solve(0,0);
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