#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int s1 = 0;
        int s2 = 0;
        for(int i=0;i<n;++i){
            if(students[i] == 1)
                s1++;
            else s2++;
        }    
        for(int i=0;i<n;++i){
            if(sandwiches[i] == 0 && s2){
                --s2;
            }
            else if(sandwiches[i] == 1 && s1){
                --s1;
            }
            else return (n - i);
        }
        return 0;
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