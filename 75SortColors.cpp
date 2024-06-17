#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1,curr=i;
        while(curr<=j){
            if(nums[curr] == 0){
                swap(nums[curr],nums[i]);
                ++i;
                ++curr;
            }
            else if(nums[curr] == 2){
                swap(nums[curr], nums[j]);
                --j;
            }
            else ++curr;
        }
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