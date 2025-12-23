#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int charDef(char &ch){
        switch(ch){
            case 'a': return 0;
            case 'e': return 0;
            case 'i': return 0;
            case 'o': return 0;
            case 'u': return 0;
            case 'A': return 0;
            case 'E': return 0;
            case 'I': return 0;
            case 'O': return 0;
            case 'U': return 0;
            case '0': return 1;
            case '1': return 1;
            case '2': return 1;
            case '3': return 1;
            case '4': return 1;
            case '5': return 1;
            case '6': return 1;
            case '7': return 1;
            case '8': return 1;
            case '9': return 1;
        }

        if((ch>='a' && ch<='z') || ch>='A' && ch<='Z')
            return 2;
        return 3;
    }
    bool isValid(string word) {
        int minLen = 0; bool vowel = false, consonant = false;
        for(char x: word){
            ++minLen;
            int n =  charDef(x);
            if(n == 3) return false;
            if(n == 0) vowel = true;
            if(n == 2) consonant = true;
        }    
        return ((minLen > 2) && vowel && consonant);
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