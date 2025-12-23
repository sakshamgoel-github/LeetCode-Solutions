#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int factorial(int n){
        long long MOD = 1e9+7;
        int fact = 1;
        for(int i=2;i<=n;++i){
            fact = (fact * 1LL * i)%MOD;
        }

        return fact;
    }
    int countPermutations(vector<int>& complexity) {
        bool flag = true;
        for(int i=1;i<complexity.size();++i){
            if(complexity[i] <= complexity[0]){
                flag = false;
                break;
            }
        }

        if(!flag) return 0;
        int n = complexity.size()-1;
        return factorial(n);
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