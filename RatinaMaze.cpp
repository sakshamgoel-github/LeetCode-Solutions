#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

int n;
bool isValid(int i, int j, vector<vector<int>>&graph){
    if(i < 0 || j<0 || i>=n || j>= n)
    return false;
    if(!graph[i][j])
    return false;
    return true;
}
vector<string>ans;

void dfs(int i, int j, string &path,vector<vector<int>>&graph, vector<vector<bool>>&vis){
    if(!isValid(i,j,graph) || vis[i][j])
    return;

    if((i == (n-1)) && (j == (n-1))){
    ans.push_back(path);return;
    }

    vis[i][j] = true;

    path.push_back('U');
    dfs(i-1,j,path,graph,vis);
    path.pop_back();

    path.push_back('R');
    dfs(i,j+1,path,graph,vis);
    path.pop_back();
    
    path.push_back('D');
    dfs(i+1,j,path,graph,vis);
    path.pop_back();
    
    path.push_back('L');
    dfs(i,j-1,path,graph,vis);
    path.pop_back();

    vis[i][j] = false;
}

vector<string> ratMaze(vector<vector<int>> &mat) {
    n = mat.size();
    string path = "";
    vector<vector<bool>>vis(n,vector<bool>(n,false));
    dfs(0,0,path, mat,vis);
    return ans;
}

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}