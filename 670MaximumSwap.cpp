#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int maximumSwap(int num) {
        vector<int>v;
        vector<int>t;
        while(num){
            v.push_back(num%10);
            t.push_back(num%10);
            num/=10;
        }    
        sort(t.begin(), t.end());
        reverse(t.begin(), t.end());
        reverse(v.begin(), v.end());

        int i=0;
        while(i < v.size()){
            if(v[i] != t[i])
                break;
            ++i;
        }
        if(i != v.size()){            
        int digit = t[i];
        int j=v.size()-1;
        while(j >= 0){
            if(v[j] == digit)
                break;
            --j;
        }
        swap(v[i], v[j]);}
        for(int &x: v){
            num*=10;
            num+=x;
        }
        return num;
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