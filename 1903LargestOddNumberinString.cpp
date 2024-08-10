#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    bool isOdd(char ch){
        if(ch == '1' || ch == '3' || ch == '5' || ch == '7' || ch == '9') return true;
        return false;
    }
    string largestOddNumber(string num) {
        string ans = "";
        int i = num.length();
        while(i > 0){
            if(isOdd(num[i-1])) break;
            --i;
        }
        for(int k = 0 ; k < i;++k) ans += num[k];
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