#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    float diameter, keliling;

    cout << " Aplikasi penghitung keliling lingkaran " << endl;
    cout << " _________________________________________ " << endl;

    cout << " Masukkan diameter : ";
    cin >> diameter;

    keliling = 3.14159 * diameter;
    cout << " Keliling lingkaran adalah : " << keliling << endl;

    cout << " _________________________________________ " << endl;
    cout << "PROGRAM SELESAI" << endl;
    return 0;
}