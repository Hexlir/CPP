#include <bits/stdc++.h>
#define standar using namespace std

standar;

double volumekubus(double sisi)
{
    return sisi * sisi * sisi;
}

double luaslingkaran(double jari)
{
    return 3.14 * jari * jari;
}

double volumesilinder(double jari, double tinggi)
{
    return luaslingkaran(jari) * tinggi;
}

int main(int argc, char const *argv[])
{
    double sisi, jari, tinggi;

    while (true){
        cout << " APLIKASI KALKULASI " << endl;
        cout << " 1. Volume Kubus " << endl;
        cout << " 2. Volume Silinder " << endl;
        cout << " 3. Luas Lingkaran " << endl;
        cout << " 4. Keluar " << endl;
        cout << " Masukkan pilihan : ";
        cin >> int pilihan;

        switch (pilihan)
        {
        case 1:
            cout << " Masukkan sisi : ";
            cin >> sisi;
            cout << " Volume Kubus : " << volumekubus(sisi) << endl;
            break;
        case 2:
            cout << " Masukkan jari-jari : ";
            cin >> jari;
            cout << " Masukkan tinggi : ";
            cin >> tinggi;
            cout << " Volume Silinder : " << volumesilinder(jari, tinggi) << endl;
            break;
        case 3:
            cout << " Masukkan jari-jari : ";
            cin >> jari;
            cout << " Luas Lingkaran : " << luaslingkaran(jari) << endl;
            break;
        case 4:
            cout << " Terima kasih " << endl;
            break;
        default:
            cout << " Pilihan tidak ada " << endl;
            get.input();
            break;
        }

    return 0;
}
