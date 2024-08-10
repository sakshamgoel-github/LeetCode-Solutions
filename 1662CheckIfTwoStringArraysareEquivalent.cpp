#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        int n1 = word1.size();    
        int n2 = word2.size();

        int ptr1 = 0, ptr2 = 0, i = 0, j = 0;
        while(ptr1 < n1 && ptr2 < n2){
            if(word1[ptr1][i] != word2[ptr2][j]) return false;
            ++i;
            ++j;
            if(i == word1[ptr1].length()){
                ++ptr1;
                i = 0;
            }
            if(j == word2[ptr2].length()){
                ++ptr2;
                j = 0;
            }
        }
        if( ptr1 == n1 && ptr2 == n2) return true;
        return false;
        
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