#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    int cap;
    list<pair<int,int>> dll;
    unordered_map<int, list<pair<int,int>>::iterator> mp;

public:
    LRUCache(int capacity) { cap = capacity; }

    int get(int key) {
        if (!mp.count(key)) return -1;

        auto it = mp[key];
        int val = it->second;

        dll.erase(it);
        dll.push_front({key, val});
        mp[key] = dll.begin();

        return val;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            dll.erase(mp[key]);
        } else if (dll.size() == cap) {
            auto last = dll.back();
            mp.erase(last.first);
            dll.pop_back();
        }

        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};

int main() {
    int capacity, q;
    cin >> capacity >> q;

    LRUCache cache(capacity);

    while (q--) {
        string op;
        cin >> op;

        if (op == "put") {
            int k, v;
            cin >> k >> v;
            cache.put(k, v);
        } else {
            int k;
            cin >> k;
            cout << cache.get(k) << endl;
        }
    }

    return 0;
}
