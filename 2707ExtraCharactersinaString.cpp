#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
	vector<int>t;
	unordered_map<string, bool>ump;
public:
	int solve(int ind, string &s){
		if(ind == s.length())
			return 0;
		if(t[ind] != -1)
			return t[ind];
		string curr = "";
		int mini = s.length();
		for (int i = ind; i < s.length(); ++i)
		{
			curr.push_back(s[i]);
			int currExtra = curr.length();
			if(ump.find(curr) != ump.end()){
				currExtra = 0;
			}
			int t = currExtra + solve(i+1,s);
			mini = min(t,mini);
		}
		return t[ind]=mini;
	}
    int minExtraChar(string s, vector<string>& dictionary) {
 		for(auto &word:dictionary)
 			ump[word] = true;
 		t.resize(s.length()+1,-1);
 		return solve(0,s);
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