#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    vector<string> words;
    string target;
    int n, m,p;
    vector<long long int>freq[26];
    vector<vector<int>>t;
    int MOD = 1e9 + 7;
public:
    int func(int a, int b){
        if(a == n)
        return 1;
        if(b == p)
        return 0;
        if(t[a][b]!=-1)
        return t[a][b];
        int not_taken = func(a,b+1) % MOD;
        int taken = (freq[target[a] - 'a'][b] * func(a+1,b+1))%MOD;
        return t[a][b] = (taken + not_taken)%MOD;
    }

    int numWays(vector<string> &words, string target)
    {
        this->words = words;
        this->target = target;
        n = target.length();
        p = words[0].length();
        for(int i=0; i<26; ++i){
            freq[i].resize(p);
        }
        for(auto s:words){
            for (int i = 0; i < p; i++)
            {
                freq[s[i] - 'a'][i]++;
            }            
        }
        t.resize(n+1,vector<int>(p+1,-1));
        return func(0,0);
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