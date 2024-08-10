#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int>ans;
        int i=0, j=0;
        int n1 = nums1.size(), n2 = nums2.size();
        while(i < n1 && j < n2){
            
            if(nums1[i] < nums2[j])
                ++i;
            
            else if(nums1[i] > nums2[j])
                ++j;
            
            else {
                ans.push_back(nums1[i]); 
                while(i < n1 && nums1[i] == ans.back()){
                ++i;            
                }
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