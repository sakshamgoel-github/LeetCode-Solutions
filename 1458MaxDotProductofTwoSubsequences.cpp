#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    int t[501][501];
public:
    int solve(int i, int j, vector<int> &nums1, vector<int> &nums2){
        if(i == nums1.size() || j == nums2.size()) return -1e9;
        if(t[i][j] != -1) return t[i][j];
        int choice1 = nums1[i]*nums2[j] + solve(i+1,j+1,nums1,nums2); //select both and solve further
        int choice2 = nums1[i]*nums2[j];//select both and do not solve further
        int choice3 = solve(i, j+1, nums1, nums2);//select only i not j
        int choice4 = solve(i+1, j, nums1, nums2);//select only j not i
        return t[i][j] = max({choice1,choice2, choice3, choice4});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(t,-1,sizeof(t));       
        return solve(0,0,nums1, nums2);

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