#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
 
class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int n = people.size();
        sort(people.begin(), people.end());
        int i = 0, j = n - 1, boats = 0;
        while (i <= j)
        {
            ++boats;
            if (people[i] + people[j] <= limit)
                ++i;
            --j;
        }
        return boats;
    }
};

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    Solution obj;
    vector<int> people = {3, 5, 3, 4};
    int limit = 5;
    cout << obj.numRescueBoats(people, limit);
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}