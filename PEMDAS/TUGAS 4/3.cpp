
#include "bits/stdc++.h"

using namespace std;

int main(){
    float a,b,c;

    cout << "Masukkan nilai a, b, c : ";
    cin >> a >> b >> c;

    cout << "Nilai Terbesar adalah : " << (a > b ? (a > c ? a : c) : (b > c ? b : c)) << endl;
}