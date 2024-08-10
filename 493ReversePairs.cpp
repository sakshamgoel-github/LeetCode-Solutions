#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    int N;
    long long int ans;
    vector<int> NUMS;

public:
    void merge(int l, int mid, int r)
    {
        int j = mid + 1;
        for (int i = l; i <= mid; i++)
        {
            while (j <= r && (NUMS[i] * 1LL > 2LL * NUMS[j]))
                ++j;
            ans += j - (mid+1);
        }

        sort(NUMS.begin()+l,NUMS.begin()+r+1);
    }
    void mergeSort(int l, int r){
        if (r - l){
            int mid = (r+l)/2;
            mergeSort(l,mid);
            mergeSort(mid+1,r);
            merge(l,mid,r);
        }
    }
    int reversePairs(vector<int> &nums)
    {
        this->N = nums.size();
        this->NUMS = nums;
        mergeSort(0,N-1);
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