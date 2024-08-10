#include <bits/stdc++.h>
using namespace std;
#define turbo ios_base::sync_with_stdio(false);cin.tie(NULL);
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " -> "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(bool a) {cerr << a;}
void _print(int a) {cerr << a;}
void _print(double a) {cerr << a;}
void _print(long long int a) {cerr << a;}
void _print(unsigned long long a) {cerr << a;}
void _print(char a) {cerr << a;}
void _print(string a) {cerr << a;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#define endl "\n"
#define for_vect(n, v) for (ll i = 0; i < n; ++i){ll x;cin >> x;v.push_back(x);}
#define MAX_HEAP priority_queue<int>
#define MIN_HEAP priority_queue<int, vector<int>, greater<int>>
typedef long long ll;
typedef pair<int, int> pi;
const int N = INT_MAX;
const int SIZE = 1e5 + 10;

vector<int> solve(string &s, string &p){
    vector<int>ans;  //this vector will contain the final answer
    int n = s.length();
    int m = p.length();
    if(n<m) //if length string s is less than string p then no anagrams will exist
    return ans;
    int left = 0,right = m-1; //managing a window size of length equal to size of string p
    vector<int>hash_p(26); //vectors to store the hash values of string s and string p
    vector<int>hash_s(26);
    for (int i = 0; i < m; i++) //calculating hash value for string p
    {
        ++hash_p[(int)p[i]-97];
    }
    for (int i = 0; i < m; i++) //calculating hash value for string s, but only for first m characters
    {
        ++hash_s[(int)s[i]-97];
    }
    while (right<n) //applying sliding window
    {
        if (hash_p==hash_s)
        {
            ans.push_back(left);
        }
        ++right;
        if(right>=n){
            break;
        }
        ++hash_s[(int)s[right]-97]; //updating the hash value of string s 
        --hash_s[(int)s[left]-97];
        ++left;
        
    }
    
    return ans;
}

int main()
{
    turbo;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
string s,p;
cin>>s>>p;
for(auto x : solve(s,p)){
    cout<<x<<" ";
}

    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}