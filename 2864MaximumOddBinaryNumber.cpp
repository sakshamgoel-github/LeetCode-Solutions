#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = 0;
        for(char &ch: s){
            if(ch == '1') ++n;
        }      
        s.back() = '1';
        --n;
        int i=0;
        while(n--){
            s[i++] = '1';
        }
        while(i < s.length() - 1)
        s[i++] = '0';
        return s;
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