#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int appendCharacters(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        int i=0,j=0;
        while(i < n1){
            if(s[i] == t[j])
                ++j;
            ++i;
        }    
        return (n2-j);
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