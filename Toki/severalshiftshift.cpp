#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        // baca input a dan b
        bitset<2000> a, b;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++) {
            a[i] = s[i] - '0';
        }
        cin >> s;
        for (int i = 0; i < n; i++) {
            b[i] = s[i] - '0';
        }

        // cek apakah a == b
        if (a == b) {
            cout << "0\n";
            continue;
        }

        // coba melakukan operasi pada a
        vector<int> k;
        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            if (a == b) {
                found = true;
                break;
            }

            // coba operasi a<<i
            bitset<2000> c = a ^ (a << i);
            if (c.count() <= i && (c ^ b) == (b ^ a)) {
                k.push_back(i + 1);
                a = c;
                continue;
            }

            // coba operasi a>>i
            c = a ^ (a >> i);
            if (c.count() <= i && (c ^ b) == (b ^ a)) {
                k.push_back(-(i + 1));
                a = c;
                continue;
            }
        }

        if (found) {
            // output operasi yang dilakukan
            cout << k.size() << "\n";
            for (int i = 0; i < k.size(); i++) {
                cout << k[i] << " ";
            }
            cout << "\n";
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}
