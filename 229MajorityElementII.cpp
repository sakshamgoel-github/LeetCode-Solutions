#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int n = nums.size();
       int ele1, ele2, cnt1 = 0, cnt2 = 0;
       for(int i=0;i<n;++i){
           if(!cnt1 && nums[i]!=ele2){
               ele1 = nums[i];
               ++cnt1;
           }
           else if(nums[i] == ele1)
           ++cnt1;
           else if(!cnt2 && nums[i]!=ele1){
               ele2 = nums[i];
               ++cnt2;
           }
           else if(nums[i] == ele2)
           ++cnt2;
           else {
               --cnt1;
               --cnt2;
           }
       }
       cnt1 = 0, cnt2 = 0;
       for(int i=0;i<n;++i){
           if(ele1 == nums[i])
           ++cnt1;
           if(ele2 == nums[i])
           ++cnt2;
       }
       if((cnt1 > n/3)&&(cnt2 <= n/3))
       return {ele1};
       else if((cnt2 > n/3)&&(cnt1 <= n/3))
       return {ele2};
       else if((cnt1>n/3) && (cnt2 > n/3))
       return {ele1,ele2};
       return {};
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