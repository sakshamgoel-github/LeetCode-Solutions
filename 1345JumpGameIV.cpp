#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
#define debug(x)          \
    cerr << #x << " -> "; \
    _print(x);            \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(bool a)
{
    cerr << a;
}
void _print(int a) { cerr << a; }
void _print(double a) { cerr << a; }
void _print(long long int a) { cerr << a; }
void _print(unsigned long long a) { cerr << a; }
void _print(char a) { cerr << a; }
void _print(string a) { cerr << a; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(unordered_map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

#define endl "\n"
#define for_vect(n, v)         \
    for (ll i = 0; i < n; ++i) \
    {                          \
        ll x;                  \
        cin >> x;              \
        v.push_back(x);        \
    }
#define MAX_HEAP priority_queue<int>
#define MIN_HEAP priority_queue<int, vector<int>, greater<int>>
typedef long long ll;
typedef pair<int, int> pi;
const int N = INT_MAX;
const int SIZE = 1e5 + 10;

int minJumps(vector<int> &arr)
{
    int ans = 0;
    int n = arr.size();
    unordered_map<int, vector<int>> ump;
    for (int i = 0; i < n; i++)
    {
        ump[arr[i]].push_back(i);
    }
    queue<int> q;
    vector<bool> visited(n);
    q.push(0);
    visited[0] = true;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int ind = q.front();
            q.pop();
            if (ind == n - 1)
                return ans;
            int left = ind - 1;
            int right = ind + 1;
            if ((left >= 0) && !visited[left])
            {
                q.push(left);
                visited[left] = true;
            }
            if ((right <= n - 1) && !visited[right])
            {
                q.push(right);
                visited[right] = true;
            }
            for (auto x : ump[arr[ind]])
            {
                if (!visited[x])
                {
                    q.push(x);
                    visited[x] = true;
                }
            }
            ump.erase(arr[ind]);
        }
        ++ans;
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
    vector<int> nums = {7,6,9,6,9,6,9,7};
    cout << minJumps(nums);
    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}