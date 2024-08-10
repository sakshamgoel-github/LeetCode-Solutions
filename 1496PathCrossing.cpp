#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>>s;
        s.insert({0,0});
        pair<int,int>pos = {0,0};
        for(char &ch: path){
            if(ch == 'N')
                pos.second+=1;
            else if(ch == 'S')
                pos.second-=1;
            else if(ch == 'E')
                pos.first+=1;
            else
                pos.first-=1;
            
            if(s.find(pos) != s.end()) return true;
            s.insert({pos});
        }
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