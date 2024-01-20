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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *merge(ListNode *ptr1, ListNode *ptr2)
{
    if(!ptr1)
    return ptr2;
    else if(!ptr2)
    return ptr1;
    ListNode *temp, *curr1, *curr2, *res;
    if(ptr1->val<=ptr2->val){
        curr1 = ptr1;
        curr2 = ptr2;
    }
    else {
        curr1 = ptr2;
        curr2 = ptr1;
    }
    res = curr1;
    while (curr1 && curr2)
    {
        while (curr1 && curr1->val<=curr2->val)
        {
            temp = curr1;
            curr1 = curr1->next;
        }
        temp->next = curr2;
        swap(curr1,curr2);
    }
    return res;
}

ListNode *mergeSort(vector<ListNode *> &lists, int i, int j)
{
    if (i > j)
    {
        return nullptr;
    }
    int mid = i + (j - i) / 2;
    ListNode *left = mergeSort(lists, i, mid);
    ListNode *right = mergeSort(lists, mid + 1, j);
    ListNode *root = merge(left, right);
    return root;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *ans;
    int n = lists.size();
    ans = mergeSort(lists, 0, n - 1);
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
ListNode *head1 = new ListNode(10);
ListNode *curr = head1;

for (int i = 0; i < 5; i++)
{
    curr = curr -> next;
    curr = new ListNode((i*4) + 10);
}
ListNode *head2 = new ListNode(15);
ListNode *curr2 = head2;

for (int i = 0; i < 5; i++)
{
    curr2 = curr2 -> next;
    curr2 = new ListNode((i) + 15);
}
while (head1)
{
    cout<<head1 -> val <<" -> ";
    head1 = head1 -> next;
}
cout<<"\n";
while (head2)
{
    cout<<head2 -> val <<" -> ";
    head2 = head2 -> next;
}
cout<<"\n";

    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}