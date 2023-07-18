#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class LRUCache
{
    list<int> dll;
    unordered_map<int, pair<int, list<int>::iterator>> ump;
    int n;

public:
    LRUCache(int capacity)
    {
        n = capacity;
    }

    int get(int key)
    {
        if (ump.count(key))
        {
            int ans = ump[key].first;
            dll.erase(ump[key].second);
            dll.push_front(key);
            ump[key].second = dll.begin();
            return ans;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (ump.count(key))
        {
            ump[key].first = value;
            dll.erase(ump[key].second);
            dll.push_front(key);
            ump[key].second = dll.begin();
        }
        else
        {
            n--;
            if (n < 0)
            {
                int t = dll.back();
                ump.erase(t);
                dll.pop_back();
                ++n;
            }
            dll.push_front(key);
            ump[key] = {value, dll.begin()};
        }
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