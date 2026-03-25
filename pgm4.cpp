#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, string> primary, replica;

    int n;
    cin >> n;

    while (n--) {
        string op, key, value;
        cin >> op;

        if (op == "write") {
            cin >> key >> value;
            primary[key] = value;
        } else if (op == "sync") {
            replica = primary;
        } else if (op == "read") {
            cin >> key;
            cout << "Replica Value: " << replica[key] << endl;
        }
    }

    return 0;
}
