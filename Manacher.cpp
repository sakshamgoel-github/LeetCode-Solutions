#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

/*
* In O(N^2) approach we assume the current index as centre and expand until left != right.
* In Manacher we optimize by using the property that left is always mirror image of right, so we
* can assign a minimum value to the ith index equal to its mirror, and then expanding 
* until left != right
*/
class Manacher
{
    string t;
    vector<int> p;
    void build()
    {
        int n = t.length();
        p.resize(n, 0);
        int l = 0, r = 0;
        /*
         * l and r: left index and right index of previously found largest palindrome. 
         */
        for (int i = 1; i < n; ++i)
        {
            int width = 0;
            /*
            * width: no. of matching char at the left and right
            * for ex: aba => width of 'b' is 1
            */

            if (i <= r)
            {   /*
                * mirror is found using the formula:
                * mirror - l = r - i
                */
                int mirror = r - i + l; 
                width = min(p[mirror], r - i);
            }
           
            while ((i - width) >= 0 && (i + width) < n && t[i - width] == t[i + width])
                ++width;
            /*
            *We are always calculating the width extra by an amount of 1, i.e why decreasing 
            *it by using next line of code
            */
            --width;
            
            p[i] = width;

            if ((i + width) > r)
            {
                r = i + width;
                l = i - width;
            }
        }
    }

public:
    Manacher(string s)
    {
        for (char ch : s)
        {
            t.append("#");
            t += ch;
        }
        t.append("#");
        cout << t << endl;
        build();
    }
    vector<int> get() { return p; }
};

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    string s = "aaaa";
    Manacher obj(s);
    vector<int> ans = obj.get();

    for (auto x : ans)
        cout << x << " ";
    cout << endl;

    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}