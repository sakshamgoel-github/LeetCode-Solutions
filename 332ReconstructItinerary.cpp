#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    unordered_map<string, vector<string>> ump;
    vector<string> ans;
    int numTickets;

public:
    bool dfs(string city, vector<string> &path)
    {
        path.push_back(city);
        if (path.size() == numTickets + 1)
        {
            ans = path;
            return true;
        }
        vector<string>&neig = ump[city];
        for (int i = 0;i<neig.size();++i)
        {
            string c = neig[i];

            neig.erase(neig.begin()+i);
            if(dfs(c, path)) return true;
            neig.insert(neig.begin()+i, c);
        }
        path.pop_back();
        return false;
    }
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {   
        numTickets = tickets.size();
        for (auto &ticket : tickets)
        {
            string from = ticket[0];
            string to = ticket[1];
            ump[from].push_back(to);
        }
        for (auto &x : ump)
        {
            sort(x.second.begin(), x.second.end());
        }
        vector<string>path;
        dfs("JFK", path);
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