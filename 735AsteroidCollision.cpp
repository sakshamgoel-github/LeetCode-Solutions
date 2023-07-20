#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        int n = asteroids.size();
        stack<int> s;
        vector<int> ans;
        for (int i = 0; i < n; ++i)
        {
            if (asteroids[i] > 0)
            {
                s.push(asteroids[i]);
            }
            else
            {
                bool stop = false;
                while (!s.empty() && !stop)
                {
                    if (s.top() < abs(asteroids[i]))
                        s.pop();
                    else if (s.top() == abs(asteroids[i]))
                    {
                        s.pop();
                        stop = true;
                    }
                    else
                    {
                        stop = true;
                    }
                }
                if (s.empty() && !stop)
                    ans.push_back(asteroids[i]);
            }
        }
        vector<int>t;
        while(!s.empty()){
            t.push_back(s.top());
            s.pop();
        }
        reverse(t.begin(),t.end());
        for(auto x:t){
            ans.push_back(x);
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