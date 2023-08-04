#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    unordered_set<string> hash;
    int N;
    vector<int>t;
    bool solve(int ind, string &s)
    {
        if (ind >= N)
            return true;
        
        if (t[ind]!=-1)
        return t[ind];

        if(hash.find(s) != hash.end())
        return true;

        for(int l = 1;l<=N;++l){
            string temp = s.substr(ind,l);
            if(hash.find(temp) != hash.end() && solve(ind+l,s)){
                return t[ind] = true;
            }
        }
        return t[ind] = false;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        this->N = s.length();
        for (string &s : wordDict)
            hash.insert(s);
        t.resize(N+1,-1);
        return solve(0,s); 
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