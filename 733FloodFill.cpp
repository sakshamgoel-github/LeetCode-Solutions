#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    int n, m, color;
    int oldcolor;
public:
    bool isValid(int x, int y,vector<vector<int>> &image)
    {
        if (x < 0 || x >= n || y < 0 || y >= m)
            return false;
        if (image[x][y] != oldcolor)
            return false;
        if (image[x][y] == color)
            return false;
        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        if (image[sr][sc] == color)
            return image;
        this->oldcolor = image[sr][sc];
        this->color = color;
        n = image.size();
        m = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        while (!q.empty())
        {   cout<<q.size()<<"\n";
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (isValid(x + 1, y,image))
            {
                q.push({x + 1, y});
                image[x+1][y] = color;
            }
            if (isValid(x - 1, y,image))
            {
                q.push({x - 1, y});
                image[x-1][y] = color;
            }
            if (isValid(x, y + 1,image))
            {
                q.push({x, y + 1});
                image[x][y+1] = color;
            }
            if (isValid(x, y - 1,image))
            {
                q.push({x, y - 1});
                image[x][y-1] = color;
            }
        }
        return image;
    }
};

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    Solution obj;
    vector<vector<int>>img = {{1,1,1},{1,1,0},{1,0,1}};
    vector<vector<int>>ans = obj.floodFill(img, 1, 1, 2);
    for(auto x: ans){
        for(auto y:x) cout<<y<<" ";
        cout<<endl;
    }
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}