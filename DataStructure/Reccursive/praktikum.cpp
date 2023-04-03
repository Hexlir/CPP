#include "bits/stdc++.h"

using namespace std;

int pow(int var, int pangkat){
    if(pangkat == 0) return 1;
    else return var * pow(var, pangkat-1);
}

int main(){
    int var, pangkat;
    printf("Masukkan angka: ");
    scanf("%d", &var);
    printf("Masukkan pangkat: ");
    scanf("%d", &pangkat);
    int hasil = pow(var, pangkat);
    printf("%d pangkat %d adalah %d", var, pangkat, hasil);
    return 0;
}