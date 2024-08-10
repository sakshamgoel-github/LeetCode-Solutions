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

void solve(vector<int> &nums, int n)
{
    for (int i = 1; i < 2 * n - 1; i++)
    {
        int new_pos = 0, curr_pos = i, currNum = nums[curr_pos], newNum = 0;
        while (currNum > 0)
        {
            if (curr_pos < n)
            {
                new_pos = 2 * curr_pos;
            }
            else
            {
                new_pos = 2 * (curr_pos - n) + 1;
            }
            newNum = nums[new_pos];
            nums[new_pos] = -currNum;
            currNum = newNum;
            curr_pos = new_pos;
        }
    }
    for (int i = 1; i < 2 * n - 1; i++)
    {
        nums[i] = -nums[i];
    }
}

int main()
{
    turbo;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    int n;
    cin >> n;
    vector<int> nums(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> nums[i];
    }
    solve(nums, n);
    for (auto x : nums)
    {
        cout << x << " ";
    }

    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}