#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string>t;
        for(auto path: paths){
            t.insert(path[1]);
        }
        for(auto path: paths){
            if(t.find(path[0])!=t.end()) t.erase(path[0]);
        }
       return *t.begin();
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