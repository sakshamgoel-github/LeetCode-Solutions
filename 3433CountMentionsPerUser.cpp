#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);


class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [](vector<string>&a, vector<string>&b){
            int t1 = stoi(a[1]);
            int t2 = stoi(b[1]);
            if(t1 < t2)
                return true;
            else if(t1 == t2){
                if(a[0] == "MESSAGE" && b[0] == "OFFLINE")
                    return false;
                else if(a[0] == "OFFLINE" && b[0] =="MESSAGE")
                    return true;
                return true;
            }
            return false;
        });
        
        vector<int> mentions(numberOfUsers);
        vector<int> online(numberOfUsers, -1);
        for(vector<string>&event: events){
            if(event[0] == "MESSAGE"){
                if(event[2] == "ALL"){
                    for (int i = 0; i < numberOfUsers; i++)
                    {
                        ++mentions[i];
                    }                    
                } else if (event[2] == "HERE"){
                    int time = stoi(event[1]);
                    for (int i = 0; i < numberOfUsers; i++)
                    {
                        if(online[i] <= time){
                            ++mentions[i];
                        }
                    }
                    
                } else {
                    int time = stoi(event[1]);
                    int i=2; int n = event[2].length();
                    string idx = "";
                    while (i<n)
                    {
                        if(event[2][i] == ' '){
                            ++mentions[stoi(idx)];
                            idx = "";
                            i += 3;
                        } else {
                            idx += event[2][i];
                            ++i;
                        }
                    }                    
                    ++mentions[stoi(idx)];
                }
            } else {
                int time = stoi(event[1]);
                online[stoi(event[2])] = time + 60;
            }
        }
        return mentions;
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