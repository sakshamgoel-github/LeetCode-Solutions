#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define turbo                                                                  \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);

  class Solution {
      int rows, cols;

  public:
      void dfs(int i, int j, vector<vector<int>>& grid,
               vector<vector<bool>>& vis) {
          if (i >= rows || j >= cols || i == -1 || j == -1 || grid[i][j] == 0 ||
              vis[i][j] == true)
              return;
          vis[i][j] = true;
          dfs(i + 1, j, grid, vis);
          dfs(i - 1, j, grid, vis);
          dfs(i, j + 1, grid, vis);
          dfs(i, j - 1, grid, vis);
      }
      int numOfIslands(vector<vector<int>>& grid) {
          int islands = 0;
          vector<vector<bool>> vis(rows, vector<bool>(cols));
          for (int i = 0; i < rows; ++i) {
              for (int j = 0; j < cols; ++j) {
                  if (grid[i][j] == 1 && !vis[i][j]) {
                      dfs(i, j, grid, vis);
                      ++islands;
                  }
              }
          }
          return islands;
      }
      int minDays(vector<vector<int>>& grid) {
          rows = grid.size();
          cols = grid[0].size();
          int islands = numOfIslands(grid);
          cout << islands;
          if (islands == 0 || islands > 1)
              return 0;
          for (int i = 0; i < rows; ++i) {
              for (int j = 0; j < cols; ++j) {
                  if (grid[i][j] == 1) {
                      grid[i][j] = 0;
                      islands = numOfIslands(grid);
                      if (islands == 0 || islands > 1)
                          return 1;
                      grid[i][j] = 1;
                  }
              }
          }
          return 2;
      }
  };

int main() {
  turbo;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);

  // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" <<
  // endl;
  return 0;
}
