#include "stdio.h"

int main(){
    float nilai[3],*penunjuk;

    nilai[0] = 220;
    nilai[1] = 641;
    nilai[2] = 53;
    penunjuk = &nilai[0];
    printf("Nilai %f ada di alamat %p \n", *penunjuk, penunjuk);
    printf("Nilai %f ada di alamat %p \n", *(penunjuk+1), penunjuk+1);
    printf("Nilai %f ada di alamat %p \n", *(penunjuk+2), penunjuk+2);

    return 0;
}