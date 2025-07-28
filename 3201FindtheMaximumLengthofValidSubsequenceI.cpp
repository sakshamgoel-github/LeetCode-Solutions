#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        bool flag = !(nums[0]%2);
        int len = 1;
        int curr = 1;
        for(int i=1;i < nums.size();++i){
            if(nums[i]%2 == flag){
                ++curr;
                flag=!flag;
            }
        }
        len = curr;
        flag = 1; curr = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]%2 == flag)
                ++curr;
        }
        len = (len > curr) ? len : curr;
        
        flag = 0;curr = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]%2 == flag)
                ++curr;
        }
        len = (len > curr) ? len : curr;
        return len;
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