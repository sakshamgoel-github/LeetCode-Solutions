#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

int n;
bool isValid(int node, int c, vector<vector<int>>&graph,vector<int>&colour){
    for(int i = 0;i<n;++i){
        if(graph[node][i] && colour[i] == c)
        return false;
    }
    return true;
}
bool solve(int node,int m, vector<vector<int>> &graph, vector<int>&colour){
    if(node == n)
    return true;

    for(int i = 1;i<=m;++i){
        if(isValid(node,i,graph,colour))
        {
            colour[node] = i;
            if(solve(node+1,m,graph,colour))
            return true;
            colour[node] = 0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    n = mat.size();
    vector<int>colour(n,0);
    if(solve(0,m,mat,colour))
    return "YES";
    return "NO";
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