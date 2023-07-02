#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);


class Solution {
    int BinarySearch(vector<int>&arr, int &target){
        int lo = 0, hi = arr.size()-1;
        int mid;

        while (lo < hi)
        {
            mid = lo + (hi-lo)/2;
            if(arr[mid] > target){
                hi = mid;
            }
            else lo = mid + 1;
        }
        return hi;
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        
    }

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
};