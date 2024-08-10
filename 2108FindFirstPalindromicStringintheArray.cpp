#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    bool check(string &word){
        int n = word.length();
        for (int i = 0; i < n/2; i++)
        {
            if(word[i] != word[n - i -1])
                return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(string &x: words){
            if(check(x))
                return x;
        }
        return "";
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