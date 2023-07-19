#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int sum[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                sum[i][j] = arr[i][j];
            } else if (i == 0) {
                sum[i][j] = sum[i][j - 1] + arr[i][j];
            } else if (j == 0) {
                sum[i][j] = sum[i - 1][j] + arr[i][j];
            } else {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
            }
        }
    }
    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        x2--;
        y2--;
        int ans = sum[x2][y2];
        if (x1 > 0) {
            ans -= sum[x1 - 1][y2];
        }
        if (y1 > 0) {
            ans -= sum[x2][y1 - 1];
        }
        if (x1 > 0 && y1 > 0) {
            ans += sum[x1 - 1][y1 - 1];
        }
        cout << ans << endl;
    }
}