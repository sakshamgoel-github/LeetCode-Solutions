#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int ans = 0;
            for(int num=low;num<=high;++num){
                if(num >= 11 && num <= 99 && num%11 == 0)
                    ++ans;
                else if(num >= 1001 && num <= 9999){
                    int sum = 0;
                    sum += num/1000;
                    sum += (num/100)%10;
                    sum -= (num/10)%10;
                    sum -= num%10;
    
                    if(sum == 0) ++ans;
                }
            }
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