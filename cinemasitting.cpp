
#include "bits/stdc++.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1) {
                ans++;
                if (i + 1 < n && a[i + 1][j] == 1) {
                    ans++;
                }
                if (j + 1 < n && a[i][j + 1] == 1) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}