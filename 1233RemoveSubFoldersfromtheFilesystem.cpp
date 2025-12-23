#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    static bool custom(string &a, string &b){
        if(a.length() < b.length())
            return true;
        return false;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end(), custom);      
        unordered_set<string>s;
        for(string &f: folder){
            string t = "/"; bool flag = true;
            int i=1;
            while(f[i] != '\0'){
                t.push_back(f[i++]);
                if(f[i] == '/' && s.find(t) != s.end()){
                    flag = false;
                    break;
                }

            }
            if(flag) s.insert(f);
        }
        vector<string>ans;
        for(auto x: s){
            ans.push_back(x);
        }
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