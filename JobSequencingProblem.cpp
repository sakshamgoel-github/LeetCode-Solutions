#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
bool compare(Job &a, Job &b)
{
    return a.profit > b.profit;
}
class Solution
{
public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        int maxtime = 0;
        for (int i = 0; i < n; ++i)
        {
            maxtime = max(maxtime, arr[i].dead);
        }
        vector<bool> slots(maxtime+1, false);
        sort(arr, arr + n, compare);
        int ans = 0,cnt = 0;
        for(int i=0;i<n;++i){
            int d = arr[i].dead;
            int p = arr[i].profit;
            int k = d;
            while (k>0 && slots[k])
            {
                --k;
            }
            if(k != 0){
                slots[k] = true;
                ans += p;
                ++cnt;
            }
        }
        return {cnt,ans};
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