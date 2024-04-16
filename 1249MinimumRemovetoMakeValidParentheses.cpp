#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string t = "";
        int open = 0;
        for(int i=0;i<s.length();++i){
            if(s[i] == '('){
                t.push_back(s[i]);
                ++open;
            }
            else if(s[i] == ')' && open){
                --open;
                t.push_back(s[i]);
            }
            else if(s[i] >= 'a' && s[i] <= 'z')
                t.push_back(s[i]);
        }
        string ans = "";
        for(int i=t.length()-1;i>=0;--i){
            if(t[i] == '(' && open){
                --open;
            }
            else{
                ans += t[i];
            }
        }
        reverse(ans.begin(), ans.end());
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