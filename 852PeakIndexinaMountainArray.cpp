#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lo = 1, hi = arr.size()-2,mid;
        while(lo <= hi){
            mid = ((hi-lo)/2)+lo;
            if (arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1])
            return mid;
            else if (arr[mid] < arr[mid+1]){
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return hi;
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