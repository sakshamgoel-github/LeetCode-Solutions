#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, 
        int firstPerson) {            
            vector<int>minTime(n,INT_MAX);
            minTime[0] = 0;
            minTime[firstPerson] = 0;

            vector<pair<int,int>> graph[n];
            for(auto &x: meetings){
                graph[x[0]].push_back({x[1], x[2]});
                graph[x[1]].push_back({x[0], x[2]});
            }

            queue<pair<int,int>>q;
            q.push({0,0});
            q.push({firstPerson,0});

            while (!q.empty())
            {
                auto curr = q.front();
                q.pop();
                if(curr.second > minTime[curr.first])
                    continue;
                for(auto &child: graph[curr.first]){
                    if(child.second >= curr.second && minTime[child.first] > child.second){
                        q.push({child.first, child.second});
                        minTime[child.first] = child.second;
                    }
                }
            }
            vector<int>ans;
            for(int i=0;i<n;++i){
                if(minTime[i] < INT_MAX)
                    ans.push_back(i);
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