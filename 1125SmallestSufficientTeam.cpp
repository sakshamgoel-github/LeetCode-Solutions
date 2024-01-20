#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
    int ReqSkills;
    vector<int> People;
    int N;
    vector<vector<int>>t;
    vector<vector<int>>u;
public:
    int solve(int i, int skillsGathered)
    {
        if (skillsGathered == ReqSkills)
        {
            return 0;
        }
        
        if ( i == N){
            return 1e4;
        }
        
        if (t[skillsGathered][i]!=-1)
        return t[skillsGathered][i];

        int ans1 = solve(i+1,skillsGathered | People[i]) + 1;
        int ans2 = solve(i+1,skillsGathered);

        if(ans1 < ans2)
        u[skillsGathered][i] = 1;

        return t[skillsGathered][i] = min(ans1,ans2);
    }
    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people)
    {
        this->N = people.size();
        int m = req_skills.size();
        this->ReqSkills = (1 << m) - 1;

        unordered_map<string, int> mpp;
        for (int i = 0; i < m; ++i)
            mpp[req_skills[i]] = (1 << i);

        for (auto it : people)
        {
            int mask = 0;
            for (int j = 0; j < it.size(); ++j)
            {
                if (mpp.count(it[j]))
                    mask |= mpp[it[j]];
            }
            People.push_back(mask);
        }
        t.resize(ReqSkills+1,vector<int>(N+1,-1));
        u.resize(ReqSkills+1,vector<int>(N+1,0));
        cout<<solve(0, 0);

        vector<int>res;
        for(int i=0,mask = 0;i<N;++i){
            if(u[mask][i]){
                res.push_back(i);
                mask |= People[i];
            }
            if(mask == ReqSkills)
            break;
        }
        return res;
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