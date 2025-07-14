#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            int n = recipes.size();
            unordered_set<string>avlSupplies;
            vector<string>ans;
            vector<int>indegree(n,0);
            unordered_map<string,vector<int>>ump;
            queue<int>q;
    
            for(string &s: supplies){
                avlSupplies.insert(s);
            }
    
            for(int i=0;i<n;++i){
                for(string &ing: ingredients[i]){
                    if(avlSupplies.find(ing) == avlSupplies.end()){
                        ump[ing].push_back(i);
                        ++indegree[i];
                    }
                }
            }
    
            for(int i=0;i<n;++i){
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
    
            while(!q.empty()){
                int i = q.front();
                q.pop();
                ans.push_back(recipes[i]);
                for(auto &x: ump[recipes[i]]){
                    indegree[x]--;
                    if(indegree[x] == 0)
                        q.push(x);
                }
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