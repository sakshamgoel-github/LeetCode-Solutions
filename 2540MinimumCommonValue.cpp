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

int func(vector<int>&nums1,vector<int>&nums2 ){
    int n = nums1.size();
    int m = nums2.size();
    int i=0, j=0;
    while (i<n && j<m)  
    {
        if(nums1[i]==nums2[j])
        return nums1[i];
        while (nums1[i]<nums2[j] && i<n)
        {
            ++i;
        }
        while (nums1[i]>nums2[j] && j<m)
        {
            ++j;
        }
        
    }
    return -1;
}

int main()
{
    turbo;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
int n,m;
cin>>n>>m;
vector<int>nums1(n);
vector<int>nums2(m);
for(int i=0;i<n;++i){
    cin>>nums1[i];
}
for(int i=0;i<m;++i){
    cin>>nums2[i];
}
cout<<func(nums1,nums2);
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}