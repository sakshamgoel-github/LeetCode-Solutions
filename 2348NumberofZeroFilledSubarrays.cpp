#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

int sum(int n){
    long long int ans = 0;
    ans = ((n)*1LL*(n+1))/2;
    return ans;
}

long long zeroFilledSubarray(vector<int>& nums) {
    int n = nums.size();
    long long int ans = 0;
    int i = 0;
    while (i<n)
    {   
        int cnt = 0;
        while ((i<n) && (nums[i]==0))
        {
            ++cnt;
            ++i;
        }
        ans+=sum(cnt);
        ++i;
    }
    return ans;
}

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    vector<int>v = {2,10,2019};
    cout<<zeroFilledSubarray(v);
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}