#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        int curr = 0;
        for(int i=0;i<n2;++i){
            int ele = arr2[i];
            for(int j=curr;j<n1;++j){
                if(arr1[j] == ele){
                    swap(arr1[j],arr1[curr]);
                    ++curr;
                }
            }
        }
        sort(arr1.begin()+curr,arr1.end());
        return arr1;
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