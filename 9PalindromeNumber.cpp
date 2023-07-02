#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    bool isPalindrome(int x){
    if(x<0 || x!=0 && x%10 ==0 ) return false;
    int check=0;
    while(x>check){
        check = check*10 + x%10;
        x/=10;
    }
    return (x==check || x==check/10);
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