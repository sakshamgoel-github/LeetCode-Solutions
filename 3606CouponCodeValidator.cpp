#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    bool validCode(string &code){
        if(code.length() == 0) return false;
        for(char &ch: code){
            if(ch == '_' || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
                continue;
            return false;
        }
        return true;
    }
    bool validBusiness(string &businessLine){
        if(businessLine == "electronics")
            return true;
        else if(businessLine == "grocery")
            return true;
        else if(businessLine == "pharmacy")
            return true;
        else if(businessLine == "restaurant")
            return true;
        return false;
    }
public:
    vector<string> validateCoupons(vector<string>& code, 
        vector<string>& businessLine, vector<bool>& isActive) {
            vector<pair<string, string>>v;
            for(int i=0;i<code.size();++i){
                if(isActive[i] && validCode(code[i]) && validBusiness(businessLine[i])){
                    v.push_back({businessLine[i],code[i]});
                }
            }
            sort(v.begin(), v.end());
            vector<string>ans;
            for(auto &x: v){
                ans.push_back(x.second);
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