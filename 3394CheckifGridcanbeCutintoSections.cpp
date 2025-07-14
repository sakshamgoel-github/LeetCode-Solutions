#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
    public:
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            sort(rectangles.begin(),rectangles.end());
            int cuts = 0;
    
            pair<int,int>p = {rectangles[0][0],rectangles[0][2]};
            for(int i=1;i<rectangles.size();++i){
                pair<int,int>t = {rectangles[i][0],rectangles[i][2]};
                if(t.first < p.second){
                    p.second = (p.second > t.second ? p.second : t.second);            
                } else{
                    ++cuts;
                    p = t;
                }
                if(cuts == 2) return true;
            }
    
            cuts = 0;
            sort(rectangles.begin(),rectangles.end(), [](const vector<int>&a, const vector<int>&b){return a[1] < b[1];});
            p = {rectangles[0][1],rectangles[0][3]};
            for(int i=1;i<rectangles.size();++i){
                pair<int,int>t = {rectangles[i][1],rectangles[i][3]};
                if(t.first < p.second){
                    p.second = (p.second > t.second ? p.second : t.second);            
                } else{
                    ++cuts;
                    p = t;
                }
                if(cuts == 2) return true;
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