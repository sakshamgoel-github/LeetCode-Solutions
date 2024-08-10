#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int j = 0, n = word.length();
        while(j < n && ch != word[j])
            ++j;
        if(j == n)
            return word;
        for(int i=0;i<=j/2;++i){
            swap(word[i], word[j - i]);
        }    
        return word;
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