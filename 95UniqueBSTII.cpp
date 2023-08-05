#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    map<pair<int,int>,vector<TreeNode*>>hash;
public:
    vector<TreeNode*> solve(int start, int end){
        if(start > end)
        return {NULL};

        if(start == end)
        {TreeNode *root = new TreeNode(start);
        return {root};
        }
        if(hash.find({start,end})!=hash.end()){
            return hash[{start,end}];
        }
        vector<TreeNode *>ans;
        
        for(int i = start;i<=end;++i){
            vector<TreeNode *>leftTrees = solve(start,i-1);
            vector<TreeNode *>rightTrees = solve(i+1,end);

            for(auto l:leftTrees){
                for(auto r: rightTrees){
                    TreeNode *root = new TreeNode(i);
                    root -> left = l;
                    root -> right = r;
                    ans.push_back(root);
                }
            }
        }
        return hash[{start,end}] = ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
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