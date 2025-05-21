#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    public:
        long long minSum(vector<int>& nums1, vector<int>& nums2) {
            long long size1, size2, sum1 = 0, sum2 = 0, zeroes1 = 0, zeroes2 = 0;    
    
            size1 = nums1.size();
            size2 = nums2.size();
    
            for(int i=0;i<size1;++i){
                if(nums1[i] == 0){
                    ++zeroes1;
                    ++sum1;
                }
                else sum1+=nums1[i];
            }
    
            for(int i=0;i<size2;++i){
                if(nums2[i] == 0){
                    ++zeroes2;
                    ++sum2;
                }
                else sum2+=nums2[i];
            }
    
            if(sum1 < sum2){
                if(zeroes1 == 0) return -1;
                return sum2;
            }
            else if(sum1 == sum2) return sum1;
            
            if(zeroes2 == 0) return -1;
            return sum1;
    
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