#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n1 = nums1.size();      
        int n2 = nums2.size();
        priority_queue<long long>mh;
        for(int i=0;i<n1;++i){
            for(int j=0;j<n2;++j){
                mh.push(nums1[i]*1LL*nums2[j]);
                if(mh.size() > k) mh.pop();
            }
        }      
        return mh.top();
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