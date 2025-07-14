#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());
        vector<int> tempInterval(2);
        tempInterval = meetings[0];
        for (int i = 1; i < n; ++i)
        {
            if (meetings[i][0] <= tempInterval[1])
            {
                tempInterval[0] = (tempInterval[0] <= meetings[i][0] ? tempInterval[0] : meetings[i][0]);
                tempInterval[1] = (tempInterval[1] >= meetings[i][1] ? tempInterval[1] : meetings[i][1]);
            }
            else
            {
                days = days - (tempInterval[1] - tempInterval[0] + 1);
                tempInterval = meetings[i];
            }
        }
        days = days - (tempInterval[1] - tempInterval[0] + 1);
        return days;
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