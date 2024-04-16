#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution {
private:
    vector<vector<char>> board;
    string word;
    vector<vector<bool>> visited;
    int m, n;

    bool dfs(int i, int j, int k) {
        if (k == word.length()) return true;
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || board[i][j] != word[k]) return false;

        visited[i][j] = true;
        bool result = dfs(i + 1, j, k + 1) || dfs(i - 1, j, k + 1) || dfs(i, j + 1, k + 1) || dfs(i, j - 1, k + 1);
        visited[i][j] = false;

        return result;
    }

public:
    bool exist(vector<vector<char>>& b, string w) {
        board = b;
        word = w;
        m = board.size();
        n = board[0].size();
        visited.resize(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, 0)) return true;
            }
        }

        return false;
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