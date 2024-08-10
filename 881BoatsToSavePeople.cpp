#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        int num = 0;
        int i=0, j=n-1;
        while (i < j){
            if((people[j] + people[i]) <= limit){
                --j;
                ++i;
                ++num;
            }
            else{
                --j;
                ++num;
            }
        }
        if(i == j)
            ++num;
        return num;   
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