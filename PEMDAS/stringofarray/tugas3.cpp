// BRIEF

// Lanjutkan program nomor 2 untuk membalik string tsb, misalnya : budi 🡪 ibud

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

    cout << "Kebalikan string : ";
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        cout << str[i];
    }
    cout << endl;
    cout << "============================" << endl;

    return 0;
}
