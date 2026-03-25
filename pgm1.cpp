#include <bits/stdc++.h>
using namespace std;

class ConsistentHasher {
    map<int, string> ring;
    int replicas;

public:
    ConsistentHasher(int r) : replicas(r) {}

    int hashFn(const string &key) {
        return hash<string>{}(key) % 360;
    }

    void addServer(string server) {
        for (int i = 0; i < replicas; i++) {
            string vnode = server + "#" + to_string(i);
            ring[hashFn(vnode)] = server;
        }
    }

    string getServer(string key) {
        if (ring.empty()) return "No server";

        int h = hashFn(key);
        auto it = ring.lower_bound(h);
        if (it == ring.end()) it = ring.begin();

        return it->second;
    }
};

int main() {
    int servers, replicas, keys;
    cin >> servers >> replicas;

    ConsistentHasher ch(replicas);

    for (int i = 0; i < servers; i++) {
        string s;
        cin >> s;
        ch.addServer(s);
    }

    cin >> keys;
    for (int i = 0; i < keys; i++) {
        string key;
        cin >> key;
        cout << key << " -> " << ch.getServer(key) << endl;
    }

    return 0;
}
