#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int a = 1, d = 0, plt = 1, res = 1;
    	while(a<n && d<n){
    	    if(arr[a] <= dep[d]){
    	        ++plt;
    	        ++a;
    	    }
    	    else{
    	        --plt;
    	        ++d;
    	    }
    	    if(plt > res)
    	    res = plt;
    	}
    	return res;
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