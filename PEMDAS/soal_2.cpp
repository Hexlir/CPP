#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int panjang, lebar, luas;

    cout << "Aplikasi penghitung luas persegi panjang" << endl;
    cout << "_________________________________________" << endl;

    cout << "Masukkan panjang : ";  
    cin >> panjang;

    cout << "Masukkan lebar : ";
    cin >> lebar;

    luas = panjang * lebar;

    cout << "Luas persegi panjang adalah : " << luas << endl;

    cout << "_________________________________________" << endl;
    cout << "PROGRAM SELESAI" << endl;
    return 0;
}
