#include <iostream>

using namespace std;

int main() {
    int perulangan;
    cin >> perulangan;

    for (int i = 0; i < perulangan; i++) {
        int p, q, m;
        cin >> p >> q >> m;
        for (int j = 0; j < m; j++) {
            if (p >= q) {
                p /= 2;
            } else {
                q /= 2;
            }
        }
        cout << q << " " << p << endl;
    }
}