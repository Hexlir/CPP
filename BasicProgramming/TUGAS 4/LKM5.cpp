
#include <bits/stdc++.h>

using namespace std;

int main(){
    int pilihan;
    float sisi, jari, tinggi;
    cout << "1. Volume Kubus" << endl;
    cout << "2. Luas Lingkaran" << endl;
    cout << "3. Volume Silinder" << endl;
    cout << "Pilih : ";
    cin >> pilihan;

    switch (pilihan){
        case 1:
            cout << "Masukkan sisi : ";
            cin >> sisi;
            cout << "Volume Kubus adalah : " << pow(sisi, 3) << endl;
            break;
        case 2:
            cout << "Masukkan jari-jari : ";
            cin >> jari;
            cout << "Luas Lingkaran adalah : " << 3.14 * pow(jari, 2) << endl;
            break;
        case 3:
            cout << "Masukkan jari-jari : ";
            cin >> jari;
            cout << "Masukkan tinggi : ";
            cin >> tinggi;
            cout << "Volume Silinder adalah : " << 3.14 * pow(jari, 2) * tinggi << endl;
            break;
        default:
            cout << "Pilihan tidak ada" << endl;
            break;
    }
}