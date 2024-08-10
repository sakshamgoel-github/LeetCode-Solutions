#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class MyHashMap
{
    vector<list<pair<int, int>>> buckets;
    int size;

public:
    MyHashMap()
    {
        size = 1e4;
        buckets.resize(size);
    }

    void put(int key, int value)
    {
        int bucketNo = key % size;
        list<pair<int, int>> &chain = buckets[bucketNo];
        for (auto &it : chain)
        {
            if (it.first == key)
            {
                it.second = value;
                return;
            }
        }
        chain.emplace_back(key, value);
    }

    int get(int key)
    {
        int bucketNo = key % size;
        list<pair<int, int>> &chain = buckets[bucketNo];
        for (auto &it : chain)
        {
            if (it.first == key)
                return it.second;
        }
        return -1;
    }

    void remove(int key)
    {
        int bucketNo = key % size;
        list<pair<int, int>> &chain = buckets[bucketNo];
        for (auto it = chain.begin(); it != chain.end(); ++it)
        {
            if (it->first == key)
            {
                chain.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main()
{
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}