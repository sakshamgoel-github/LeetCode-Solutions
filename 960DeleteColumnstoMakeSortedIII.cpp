#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].length();
        vector<int>t(n,1);
        int ans = 1;
        for (int j = 1; j < n; j++){
            for (int i = 0; i < j; i++)
            {   
                bool flag = false;
                for (int row = 0; row < strs.size(); row++)
                {
                    if(strs[row][i] > strs[row][j]){
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    t[j] = max(t[j], t[i] + 1);
                    ans = max(ans, t[j]);
                }
            }
                           
        }

        return (n-ans);
        
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