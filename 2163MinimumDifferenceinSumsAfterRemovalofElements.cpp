#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;
        priority_queue<int>maxHeap;
        vector<long long int>leftSum;
        
        long long int sum = 0;
        for(int i=0;i<n;++i){
            maxHeap.push(nums[i]);
            sum+=1LL*nums[i];
        }
        leftSum.push_back(sum);
        for(int i=n;i<2*n;++i){
            if(maxHeap.top() > nums[i]){
                sum -= 1LL*maxHeap.top();
                sum += 1LL*nums[i];
                maxHeap.push(nums[i]);
                maxHeap.pop();
            }
            leftSum.push_back(sum);
        }
       
        sum = 0; vector<long long int>rightSum;
        priority_queue<int,vector<int>, greater<int>>minHeap;
        for(int i=3*n-1;i>=2*n;--i){
            minHeap.push(nums[i]);
            sum+=1LL*nums[i];
        }
        rightSum.push_back(sum);
        for(int i=2*n-1;i>=n;--i){
            if(minHeap.top() < nums[i]){
                sum -= 1LL*minHeap.top();
                sum += 1LL*nums[i];
                minHeap.push(nums[i]);
                minHeap.pop();
            }
            rightSum.push_back(sum);
        }
        reverse(rightSum.begin(), rightSum.end());
        
        long long int ans = leftSum[0] - rightSum[0];
        for(int i=1;i<n+1;++i){
            long long int curr = leftSum[i]-rightSum[i];
            ans = ans < curr ? ans : curr;
        }
        return ans;
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