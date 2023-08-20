#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
    int n1 = str1.length();
    int n2 = str2.length();
        if(n1 < n2)
            return false;
        int numDeletes = n1 - n2;
        int i = 0, j = 0;
        while(i<n1 && j<n2){
            if(str1[i] == str2[j]){
                ++i;
                ++j;
            }
            else if(str2[j] == 'a' && str1[i] == 'z'){
                ++i;
                ++j;
            }
            else if((str2[j] - str1[i]) == 1){
                ++i;
                ++j;
            }
            else{
                ++i;
                --numDeletes;
                if(numDeletes < 0)
                    return false;
            }
        }
        return true;
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