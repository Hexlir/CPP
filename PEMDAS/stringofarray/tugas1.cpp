// BRIEF

// Lakukan percobaan untuk menginputkan string dari keyboard dengan menggunakan : 
// scanf(), gets() dan fgets(). 
// Analisislah dan berikan kesimpulan untuk setiap fungsi tsb!

#include <iostream>
#include <string.h>
#include "stdio.h"


using namespace std;

int main()
{
    cout << "PERCOBAAN INPUT STRING DENGAN FUNGSI SCANF(), GETS() DAN FGETS()" << endl;
    cout << "================================================================" << endl;
    cout << "Masukkan string dengan fungsi scanf() : ";

    char str[100];
    printf("Masukkan string: ");
    scanf("%s", str);
    printf("String yang dimasukkan: %s", str);
    cout << endl;

    cout << "Masukkan string dengan fungsi gets() : ";
    char str1[100];
    gets(str1);
    printf("String yang dimasukkan: %s", str1);
    cout << endl;

    cout << "Masukkan string dengan fungsi fgets() : ";
    char str2[100];
    fgets(str2, sizeof(str2), stdin);
    printf("String yang dimasukkan: %s", str2);
    cout << endl;

    cout << "================================================================" << endl;
    cout << "KESIMPULAN" << endl;
    cout << "================================================================" << endl;
    cout << "1. Fungsi scanf() hanya dapat menginputkan string yang berupa satu kata saja" << endl;
    cout << "2. Fungsi gets() dapat menginputkan string yang berupa satu kata atau lebih" << endl;
    cout << "3. Fungsi fgets() dapat menginputkan string yang berupa satu kata atau lebih" << endl;
    cout << "================================================================" << endl;

    return 0;
}