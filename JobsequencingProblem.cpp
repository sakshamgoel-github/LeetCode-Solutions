#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

class Solution 
{
    public:
    // Static member function for comparison
    static bool compareFunc(Job &a, Job &b){
        return a.profit > b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr + n, compareFunc);

        int maxDeadline = 0;
        for (int i = 0; i < n; ++i) {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        
        vector<int> time(maxDeadline + 1, -1);
        int maxi = 0, num = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = arr[i].dead; j > 0; --j) {
                if (time[j] == -1) {
                    time[j] = i;
                    maxi += arr[i].profit;
                    ++num;
                    break;
                }
            }
        }
        
        return {num, maxi};
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