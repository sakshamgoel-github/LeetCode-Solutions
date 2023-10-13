#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    vector<int>building;
    int N;
public:
    int solve(int ind, int count,vector<vector<int>>&nums){
        if (ind == N){
            for (int i = 0; i < building.size(); i++)
            {
                if (building[i])
                return 0;
            }
            return count;
        }

        int from = nums[ind][0];
        int to = nums[ind][1];

        --building[from];
        ++building[to];
        int choice1 = solve(ind+1,++count,nums);

        --count;
        ++building[from];
        --building[to];
        int choice2 = solve(ind+1,count,nums);

        return max(choice1, choice2);
    }
    int maximumRequests(int n, vector<vector<int>>& nums) {
        building.resize(n,0);
        this->N = nums.size();
        return solve(0,0,nums);
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