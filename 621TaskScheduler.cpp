#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int l = tasks.size();
        priority_queue<pair<int,char>, vector<pair<int,char>>, greater<pair<int,char>>>mh;
        unordered_map<char, int>ump;
        for (int i = 0; i < l; i++)
        {
            ump[tasks[i]]++;
        }
        for(auto x: ump){
            mh.push({0,x.first});
        }
        int ans = 0;
        
        
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