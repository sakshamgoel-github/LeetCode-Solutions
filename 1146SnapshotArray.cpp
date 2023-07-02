#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class SnapshotArray {
    vector<vector<pair<int,int>>>v;
    int snap_id;
public:
    SnapshotArray(int length) {
        v.resize(length);
        for(int i=0;i<length;++i){
            v[i].push_back({0,0});
        }
        snap_id = 0;        
    }
    
    void set(int index, int val) {
        v[index].push_back({snap_id, val});
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(v[index].begin(), v[index].end(), make_pair(snap_id, INT_MAX));
        return prev(it)->second;
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