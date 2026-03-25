#include <bits/stdc++.h>
using namespace std;

queue<string> broker;

void producer() {
    int n;
    cin >> n;
    while (n--) {
        string event;
        cin >> event;
        broker.push(event);
    }
}

void consumer() {
    while (!broker.empty()) {
        cout << "Consumed: " << broker.front() << endl;
        broker.pop();
    }
}

int main() {
    producer();

    cout << "Processing events...\n";
    consumer();

    return 0;
}
