#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, laba = 0;;
    cin >> n;

    int harga[n];
    for (int i = 0; i < n; i++) {
        cin >> harga[i];
    }

    int beli = harga[0];

    for (int i = 1; i < n; i++) {

        if (harga[i] < beli) {
            beli = harga[i];
        } 
        else {
            laba += harga[i] - beli;
            beli = harga[i];
        }
    }

    cout << laba << endl;
}