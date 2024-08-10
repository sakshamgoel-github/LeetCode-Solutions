#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);


class FindSumPairs
{
private:
    vector<int> nums1, nums2;
    unordered_map<int,int>ump;
public:
    FindSumPairs(vector<int> &nums1, vector<int> &nums2)
    {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for(auto x:nums2){
            ++ump[x];
        }
    }

    void add(int index, int val)
    {
        this->nums1[index] += val;
    }

    int count(int tot)
    {   
        int ans = 0;
        for(auto x : this->nums1){
            ans+=ump[tot - x];
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