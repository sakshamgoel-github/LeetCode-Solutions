#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int l1 = version1.length();
        int l2 = version2.length();

        while (i < l1 && j < l2) {
            string v1 = "";
            string v2 = "";
            while (i < l1 && version1[i] != '.') {
                v1 += version1[i];
                ++i;
            }
            while (j < l2 && version2[j] != '.') {
                v2 += version2[j];
                ++j;
            }
            int n1 = v1.length() ? stoi(v1):0;
            int n2 = v2.length() ? stoi(v2):0;
            if(n1 > n2)
                return 1;
            else if(n1 < n2)
                return -1;
            ++i;
            ++j;
        }
        while(i < l1){
            string v1 = "";
            while (i < l1 && version1[i] != '.') {
                v1 += version1[i];
                ++i;
            }
            int n1 = v1.length() ? stoi(v1):0;
            if(n1 > 0)
                return 1;
            ++i;
        }
        while(j < l2){
            string v2 = "";
            while (j < l2 && version2[j] != '.') {
                v2 += version2[j];
                ++j;
            }
            int n1 = v2.length() ? stoi(v2):0;
            if(n1 > 0)
                return -1;
            ++j;
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