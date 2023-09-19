#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
int findDuplicate(vector<int> &nums)
{
    int i=nums[0],j=nums[i];
    while(i!=j){
        i=nums[i];
        j=nums[j];
        j=nums[j];
    }
    i=0;
    while(i!=j){
        i = nums[i];
        j = nums[j];
    }
    return i;
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