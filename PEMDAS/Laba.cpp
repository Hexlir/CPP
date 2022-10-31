#include <bits/stdc++.h>

using namespace std;


int main()
{
    system("cls");
    
    int harga, jumlah,laba, total;

    const float persen = 0.3;

    printf(" Aplikasi penghitung laba \n");
    printf(" _________________________________________ \n");

    printf(" Masukkan harga barang : Rp.");
    scanf("%d", &harga);

    printf(" Masukkan jumlah barang : ");
    scanf("%d", &jumlah);

    total = harga * jumlah;

    laba = total * persen;
    
    printf(" Laba yang didapat adalah : Rp.%d \n", laba);

    printf(" Total harga yang harus dibayar adalah : Rp.%d \n", total);

    printf(" _________________________________________ \n");
    printf("PROGRAM SELESAI");
    cin.get();cin.get();
    system("cls");
    return 0;
}