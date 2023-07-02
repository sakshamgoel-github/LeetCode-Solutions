#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution{
    private:
    //*key = s1 + "_" + s2
    //*value is the result
    unordered_map<string,bool>ump;
    public:
    bool isScramble(string s1, string s2){
        string key = s1 + '_' + s2;

        if(s1 == s2)
        return ump[key] = true;
        
        if(s1.length()!=s2.length())
        return ump[key] = false;
        
        if(ump.find(key)!=ump.end())
        return ump[key];

        int n = s1.length();
        
        for (int i = 1; i < n; ++i)
        {
            bool not_swapped = (isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i,n-i),s2.substr(i,n-i)));
            if(not_swapped)
            return ump[key] = true;
           
            bool swapped = (isScramble(s1.substr(i,n-i),s2.substr(0,n-i)) && isScramble(s1.substr(0,i),s2.substr(n-i,i)));
            if(swapped)
            return ump[key] = true;
            
        }
        
        return ump[key] = false;
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