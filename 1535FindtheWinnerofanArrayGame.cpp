#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int maxi = arr[0];
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi,arr[i]);
        }
        if(k >= n) return maxi;
        int winner = arr[0];int str = 0;
        for (int i = 1; i < n; i++)
        {
            if(winner > arr[i]){
                str += 1;
            }
            else {
                winner = arr[i];
                str = 1;
            }
            if(str == k || winner == maxi) return winner;
        }
        return 0;              
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