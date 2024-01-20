#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    bool isVowel(char ch){
        ch = tolower(ch);
        switch(ch){
            case 'a':
            return true;
            case 'e':
            return true;
            case 'i':
            return true;
            case 'o':
            return true;
            case 'u':
            return true;
        }
        return false;
    }
    string sortVowels(string s) {
        string vowels = "";
        for(char &ch: s){
            if(isVowel(ch))
            vowels += ch;
        }    
        sort(vowels.begin(), vowels.end());
        int j = 0, i = 0;
        while(i < s.length()){
            if(isVowel(s[i])) s[i] = vowels[j++];
            ++i;
        }
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