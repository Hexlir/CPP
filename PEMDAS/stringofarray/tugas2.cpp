// BRIEF

// Buatlah program untuk menerima input string dari keyboard kemudian 
// hitunglah panjang dari string tsb dan tampilkan hasilnya!

#include "bits/stdc++.h"

using namespace std;

int main()
{
    cout << "PROGRAM HITUNG PANJANG STRING" << endl;
    cout << "============================" << endl;

    cout << "Masukkan string : ";
    char str[100];

    fgets(str, sizeof(str), stdin);

    cout << "Panjang string : " << strlen(str) << endl;
    cout << "============================" << endl;

    return 0;
}
